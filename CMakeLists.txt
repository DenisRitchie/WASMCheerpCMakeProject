cmake_minimum_required(VERSION 3.18.4)

# if(POLICY CMP0010)
#   cmake_policy(SET CMP0010 NEW)
# endif()

project(CheerpCMakeProject
  VERSION      0.1.0.0
  DESCRIPTION  "Cheerp project configuration for Visual Studio Code with the C/C++ Language"
  HOMEPAGE_URL https://github.com/DenisRitchie/WASMCheerpCMakeProject
  LANGUAGES    C CXX
)

# include(CTest)
# enable_testing()

add_executable(
  ${CMAKE_PROJECT_NAME}
  includes/client2.hpp
  includes/events.hpp
  includes/dom_ext.hpp
  includes/dom.hpp
  main.cpp
)

target_compile_options(
  ${CMAKE_PROJECT_NAME}
    PUBLIC -Os
    PUBLIC -std=gnu++2a
    # PUBLIC -cheerp-no-credits
    # PUBLIC -cheerp-no-native-math
    # PUBLIC -cheerp-no-math-imul
    # PUBLIC -cheerp-no-math-fround
)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

configure_file(templates/index.cpphtml index.html @ONLY)

add_subdirectory(examples)

# file(
#   GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/index.html
#   INPUT ${CMAKE_CURRENT_SOURCE_DIR}/templates/index.html
# )

file(
  GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/index.css
  INPUT ${CMAKE_CURRENT_SOURCE_DIR}/templates/index.css
)

install(
  TARGETS ${CMAKE_PROJECT_NAME}
  DESTINATION bin
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/index.html
  DESTINATION bin
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/index.css
  DESTINATION bin
)
