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

# Fetch GoogleTest (or find_package)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Test executable
file(
  GLOB TEST_SOURCES
  "*.cpp"
)
list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)
# TODO: Removed temporary until stub for calculator_ui.cpp is created
list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/src/ui/calculator_ui.cpp)

add_executable(
  test_calculator ${SOURCES}
  ${TEST_SOURCES}
)

target_include_directories(
  test_calculator PRIVATE
  ${CMAKE_SOURCE_DIR}/include/core
  ${SPDLOG_H_DIR}
)
target_link_libraries(
  test_calculator PRIVATE
  ${SPDLOG_DIR}/libspdlog.a
  gtest_main
)

# Add the test executable to CTest
include(GoogleTest)
gtest_discover_tests(test_calculator)
