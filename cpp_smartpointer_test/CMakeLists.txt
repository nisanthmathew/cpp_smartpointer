cmake_minimum_required(VERSION 3.5)

project(smartpointertestcase LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(smartpointertestcase tst_smartpointertestcase.cpp)
add_test(NAME smartpointertestcase COMMAND smartpointertestcase)

target_link_libraries(smartpointertestcase PRIVATE Qt5::Test)

