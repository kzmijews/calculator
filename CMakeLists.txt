# Copyright © 2025 Karol Zmijewski
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this
# software and associated documentation files (the “Software”), to deal in the Software
# without restriction, including without limitation the rights to use, copy, modify, merge,
# publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
# to whom the Software is furnished to do so, subject to the following conditions:
# The above copyright notice and this permission notice shall be included in all copies or
# substantial portions of the Software.
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
#
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
# PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
# FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
# OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

message(STATUS "Starting CMake configuration...")
# - GENERAL SETTINGS
cmake_minimum_required(VERSION 3.10)
project(calculator)
message(STATUS "- Project: ${PROJECT_NAME}")
# -- C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "- C++ standard: 17")
message(STATUS "- CMake version: ${CMAKE_VERSION}")
# -- compiler flags
if(MSVC)
  add_compile_options(/W4 /WX)
  messgage(STATUS "- MSVC compiler flags: /W4, /WX")
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
  message(STATUS "- GCC/Clang compiler flags: -Wall, -Wextra, -pedantic, -Werror")
endif()
# -- build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  message(STATUS "- Build type: 'Release' (default)")
else()
  message(STATUS "- Build type: ${CMAKE_BUILD_TYPE}")
endif()
# - APP SETTINGS
# -- version information
set(APP_VERSION_MAJOR $ENV{APP_VERSION_MAJOR})
if(NOT APP_VERSION_MAJOR)
    set(APP_VERSION_MAJOR 0)
endif()
set(APP_VERSION_MINOR $ENV{APP_VERSION_MINOR})
if(NOT APP_VERSION_MINOR)
    set(APP_VERSION_MINOR 0)
endif()
set(APP_VERSION_PATCH $ENV{APP_VERSION_PATCH})
if(NOT APP_VERSION_PATCH)
    set(APP_VERSION_PATCH 0)
endif()
set(APP_VERSION_STRING "${APP_VERSION_MAJOR}.${APP_VERSION_MINOR}.${APP_VERSION_PATCH}")
message(STATUS "Version: ${APP_VERSION_STRING}")
configure_file(
  ${CMAKE_SOURCE_DIR}/include/core/version.hpp.in
  ${CMAKE_SOURCE_DIR}/include/core/version.hpp
)
# -- output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# -- include directories
include_directories(
  ${CMAKE_SOURCE_DIR}/include/core
  ${CMAKE_SOURCE_DIR}/include/cxxopts
  ${CMAKE_SOURCE_DIR}/include/ui
)
# -- source files
file(
  GLOB SOURCES
  "src/*.cpp"
  "src/core/*.cpp"
  "src/ui/*.cpp"
)
# -- UI files
set(
  UIS
  "src/ui/calculator.ui"
)
# -- executable target
add_executable(calculator ${SOURCES})
# -- link libraries
if(MSVC)
  target_link_libraries(calculator PRIVATE msvcrt)
else()
  target_link_libraries(calculator PRIVATE m)
endif()
# -- Qt6 settings
if(NOT DEFINED CMAKE_PREFIX_PATH AND DEFINED ENV{Qt6_DIR})
  set(CMAKE_PREFIX_PATH "$ENV{Qt6_DIR}")
elseif(NOT DEFINED CMAKE_PREFIX_PATH)
  message(FATAL_ERROR "Qt6_DIR environment variable is not set. Please set it to the Qt6 installation directory.")
else()
  message(STATUS "- Qt6_DIR: ${CMAKE_PREFIX_PATH}")
endif()
find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(
  calculator PRIVATE
  Qt6::Widgets
)
qt_wrap_ui(UI_HEADERS ${UIS})
# - DISTRIBUTION SETTINGS
# -- install rules
if(NOT DEFINED ARTIFACTS_DIRECTORY)
    set(ARTIFACTS_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
endif()
message(STATUS "ARTIFACTS_DIRECTORY: ${ARTIFACTS_DIRECTORY}")
install(
  DIRECTORY ${ARTIFACTS_DIRECTORY} DESTINATION opt/calculator/
)
# -- packaging
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "calculator")
set(CPACK_PACKAGE_VERSION "${APP_VERSION_STRING}")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}_${CPACK_PACKAGE_VERSION}_amd64")
set(CPACK_PACKAGE_DESCRIPTION "A simple calculator application.")
set(CPACK_PACKAGE_CONTACT "Karol Zmijewski")
set(CPACK_PACKAGE_VENDOR "${CPACK_PACKAGE_CONTACT}")
set(CPACK_INSTALL_DIRECTORY "opt/calculator")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "/opt/calculator")
set(CPACK_PACKAGING_INSTALL_PREFIX "/")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "${CPACK_PACKAGE_CONTACT} <karol.zmijewski@gmail.com>")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "${CPACK_PACKAGE_DESCRIPTION}")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libgl1, libegl1, libfontconfig1")
include(CPack)

message(STATUS "Makefile generated sucessfully, call make command to build the project")