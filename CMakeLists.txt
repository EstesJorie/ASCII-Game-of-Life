cmake_minimum_required(VERSION 3.30)
project(GameOfLifeA)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "/usr/local/lib/cmake/SFML")

find_package(SFML REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(GameOfLifeA main.cpp)

target_link_libraries(GameOfLifeA sfml-graphics sfml-window sfml-system)
