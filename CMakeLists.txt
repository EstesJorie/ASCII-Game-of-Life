cmake_minimum_required(VERSION 3.30)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameOfLifeA main.cpp)

find_package(SFML 3.0.0 REQUIRED COMPONENTS Graphics)


target_link_libraries(GameOfLifeA PUBLIC SFML::Graphics)
