
cmake_minimum_required(VERSION 2.6)

project(visualiseur)


file(
GLOB
source_files
*.cpp
*.c
*.h
)

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter -std=c99 -Wno-unused-variable" )


add_executable(	
   visualiseur
   ${source_files}
   )	

target_link_libraries(visualiseur "-lm -lGL -lGLU -lglut -pthread")


