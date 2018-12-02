project(${CMAKE_PROJECT_NAME}_src)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Model.h Graphics.cpp Graphics.h World.cpp World.h Vec3.h Mat3.h WorldScreenTransformer.h
        IndexedList.h Models/Cube.cpp Models/Pyramid.cpp Models/all.h ModelImporter.h objImporter.cpp timer.cpp)

add_executable(3dterm ${SOURCE_FILES})

target_link_libraries(3dterm ${CURSES_LIBRARIES})