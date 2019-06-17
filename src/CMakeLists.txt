project(${CMAKE_PROJECT_NAME}_src)

# Include ncurses lib, used to draw characters to terminal
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_package(Boost COMPONENTS filesystem program_options)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cc model.h graphics.cc graphics.h world.cc world.h vec3.h mat3.h world_screen_transformer.h
        indexed_list.h models/cube.cc models/pyramid.cc models/all.h model_importer.h obj_importer.cc timer.cc)

add_executable(3dterm ${SOURCE_FILES})

target_link_libraries(3dterm ${Boost_LIBRARIES} ${CURSES_LIBRARIES})