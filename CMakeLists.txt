# CMake file to simplify build process
# Created by Karol Zmijewski, karol.zmijewski@gmail.com.
# Released into the public domain.

# - general settings
cmake_minimum_required(VERSION 3.10)
project(calculator)
# -- C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# -- build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  message(STATUS "Setting build type to 'Release' as none was specified.")
else()
  message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
endif()
# -- output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# -- compiler flags
if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
# -- include directories
include_directories(
  ${CMAKE_SOURCE_DIR}/include/core
  ${CMAKE_SOURCE_DIR}/include/iface
  ${CMAKE_SOURCE_DIR}/include/cxxopts
)
# -- source files
file(
  GLOB SOURCES
  "src/*.cpp"
  "src/core/*.cpp"
  "src/iface/*.cpp"
)
# -- executable target
add_executable(calculator ${SOURCES})
# -- link libraries
if(MSVC)
  target_link_libraries(calculator PRIVATE msvcrt)
else()
  target_link_libraries(calculator PRIVATE m)
endif()
# -- install rules
install(
  TARGETS calculator
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
# -- packaging
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_NAME "calculator")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "A simple calculator application.")
set(CPACK_PACKAGE_CONTACT "Karol Zmijewski")
set(CPACK_PACKAGE_VENDOR "Karol Zmijewski")
include(CPack)

message(STATUS "Makefile generated sucessfully, call make command to build the project")