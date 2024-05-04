cmake_minimum_required(VERSION 3.28)

project(cpp23-modules-example CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)

add_library(bug_module)

target_sources(
    bug_module
    PUBLIC
    FILE_SET CXX_MODULES FILES
    module_that_uses_stacktrace.ixx
)

add_executable(bug_repro)

target_sources(bug_repro
  PRIVATE
  main.cpp
)

target_link_libraries(bug_repro bug_module)
