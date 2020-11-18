cmake_minimum_required(VERSION 3.10.2)
project(assignment1)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES echo.c shellmain.c catmain.c tokenizemain.c redirect.c tokenize.c tokenize.h catmain.c catmain.c cat.h cat.c)

add_executable(assignment1 ${SOURCE_FILES})