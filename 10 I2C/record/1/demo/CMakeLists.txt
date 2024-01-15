cmake_minimum_required(VERSION 3.10.0)
# 设置编译器路径
set(CMAKE_C_COMPILER "D:/MinGW/bin/gcc.exe")
project(hello)
include_directories(${PROJECT_SOURCE_DIR}/include())
aux_source_directory(${PROJECT_SOURCE_DIR}/src src)
add_executable(main ${src})