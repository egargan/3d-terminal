
#include <string>
#include <sstream>

struct ImportException : public std::exception {

 public:
  ImportException(const std::string &filename,
                  const long &line_error_detected,
                  const std::exception &e) {
    std::ostringstream message;
    message << "Error parsing file '" << filename
            << "' at line " << line_error_detected << ":\n" << e.what();
    error_message_ = message.str();
  };

  const char *what() const noexcept override {
    return error_message_.c_str();
  }

 private:
  std::string error_message_;

};