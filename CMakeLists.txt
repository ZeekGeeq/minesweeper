cmake_minimum_required(VERSION 3.24)
project(minesweeper)

set(CMAKE_CXX_STANDARD 17)

add_executable(minesweeper main.cpp Tile.h storage_space.h digits.h)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics REQUIRED)

include_directories(C:/SFML/include/SFML/Graphics)
target_link_libraries(minesweeper sfml-graphics)