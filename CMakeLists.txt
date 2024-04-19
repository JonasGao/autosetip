cmake_minimum_required(VERSION 3.28)
project(autosetip LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(autosetip main.cpp)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(autosetip ${CURL_LIBRARIES})