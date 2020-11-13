cmake_minimum_required(VERSION 3.18.4)

# http://johnnado.com/cmake-directory-variables/
# https://cmake.org/cmake/help/latest/command/project.html
# https://stackoverflow.com/questions/38938315/difference-between-cmake-project-name-and-project-name
project(EventPreventDefault
  VERSION   1.0.0.0
  LANGUAGES C CXX)

add_executable(
  ${PROJECT_NAME}
  ../../../includes/client2.hpp
  ../../../includes/events.hpp
  ../../../includes/dom_ext.hpp
  ../../../includes/dom.hpp
  main.cpp
)

# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(
  ${PROJECT_NAME}
    PUBLIC ../../../
)

target_compile_options(
  ${PROJECT_NAME}
    PUBLIC -Os
    PUBLIC -std=gnu++2a
)

# https://cmake.org/cmake/help/latest/command/file.html
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/index.cpphtml
  index.html @ONLY
)

file(
  GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/index.css
  INPUT ${CMAKE_CURRENT_SOURCE_DIR}/index.css
)

