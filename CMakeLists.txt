# CMake file to simplify build process
# Created by Karol Zmijewski, karol.zmijewski@gmail.com.
# Released into the public domain.

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
message(STATUS "Version: ${APP_VERSION}")
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
install(
  TARGETS calculator
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
# -- packaging
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_NAME "calculator")
set(CPACK_PACKAGE_VERSION "${APP_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "A simple calculator application.")
set(CPACK_PACKAGE_CONTACT "Karol Zmijewski")
set(CPACK_PACKAGE_VENDOR "Karol Zmijewski")
include(CPack)

message(STATUS "Makefile generated sucessfully, call make command to build the project")