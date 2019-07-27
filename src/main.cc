
#include "boost/filesystem.hpp"
#include "boost/program_options.hpp"
#include <thread>
#include <ostream>

#include "model.h"
#include "models/all.h"
#include "graphics.h"
#include "world.h"
#include "obj_importer.cc"

namespace po = boost::program_options;
namespace fs = boost::filesystem;

// Declares any models, adds them to a 'world' object, and performs render loop
int main(int argc, char *argv[]) {
  // Declare options that are shown to the user on '--help'
  po::options_description options("Allowed options");
  // 'add_options' defines proxy object that defines operator(), that lets us group option definitions in brackets,
  // hence the funky syntax
  options.add_options()
      ("help,h", "see help message")
      ("input-file", po::value<std::string>(), ".OBJ input file");

  // 'positional options' refer to CLI args with no option name, e.g. '--input='
  po::positional_options_description p;
  // Translate all positional options as 'input-file' options, declared above
  p.add("input-file", -1);

  // Store options in 'variables map'
  po::variables_map vm;
  // Parse options from argv into vm, by the given options description and positional description
  // TODO catch 'cannot be specified > 1' exceptions for --input-file
  po::store(po::command_line_parser(argc, argv).options(options).positional(p).run(), vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << options << "\n";
    return 0;
  }

  if (!vm.count("input-file")) {
    std::cout << "No .OBJ file given" << "\n";
    return 1;
  }

  const auto &path = vm["input-file"].as<std::string>();

  if (path.empty() || !fs::exists(path)) {
    std::cout << "Could not find file '" << path << "'" << "\n";
    return 1;
  } else if (!fs::is_regular_file(path)) {
    std::cout << "'" << path << "' is not a regular file" << "\n";
    return 1;
  }

  const auto &canpath = fs::canonical(path, fs::current_path());

  // todo: move all this + render loop into a new 'Engine' class
  Graphics gfx;
  World world(gfx);

  Model model;

  try {
    model = ObjImporter(canpath.string()).GetModel();
  } catch (const ImportException &e) {
    std::cout << e.what() << "\n";
    exit(1);
  }

  world.AddObject(model);

  while (true) {
    world.RenderObjects();
    std::this_thread::sleep_for(std::chrono::milliseconds(40));
    gfx.Refresh();
  }
}