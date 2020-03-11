cmake_minimum_required(VERSION 3.5)

project(cpp_smartpointer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)
include_directories(H:/extralearning/udemy/cpp/MyString/MyStringClass)

add_executable(cpp_smartpointer
  main.cpp
  H:/extralearning/udemy/cpp/MyString/MyStringClass/mystring.cpp
)
target_link_libraries(cpp_smartpointer Qt5::Core)
