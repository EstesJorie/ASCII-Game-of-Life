# ASCII-Game-of-Life


--------- Overview ---------

A simple ASCII re-creation of John Conway's Game of Life, written in C++20. The majority of the code is contained within the "main.cpp" which imports a series of includes from the file (stdcc++.hpp) which is contained within 'utils/bits'.

--------- Building Project Files ---------

To build a Visual Studio Solution (.sln), in the source directory open the terminal and run the command: 

cmake -B build -G 'Visual Studio 17 2022'

This builds a Visual Studio project to the 'builds' folder containde within the repo. 

There is already a pre-built XCode project file located in the folder (\_build). If this folder is not avaliable, does not work, or you just simply want to rebuild within the terminal (at the source directory) run the command:

cmake -G Xcode -H. -B_build 

------------------
