
cmake_minimum_required(VERSION 2.6)

project(jeu_siam)


file(
GLOB
source_files
*.c
*.h
)

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_C_FLAGS "-DCORRECTION -Wall -Wextra -Wno-unused-parameter -D_REENTRANT -fPIC" )


add_executable(	
   jeu_siam
   ${source_files}
   )	

target_link_libraries(jeu_siam "-lm")


