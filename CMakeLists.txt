cmake_minimum_required(VERSION 3.0.0)
project(CheerpCMake VERSION 0.1.0)

# include(CTest)
# enable_testing()

add_executable(CheerpCMake
  includes/helpers.hpp
  main.cpp
)

target_compile_options(
  CheerpCMake
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

file(
  GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/index.html
  INPUT ${CMAKE_CURRENT_SOURCE_DIR}/templates/index.html
)

install(
  TARGETS CheerpCMake
  DESTINATION bin
)

install(
  FILES ${CMAKE_CURRENT_SOURCE_DIR}/templates/index.html
  DESTINATION bin
)
