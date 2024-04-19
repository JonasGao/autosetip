cmake_minimum_required(VERSION 2.8)
project(autosetip)
ENABLE_LANGUAGE(CXX)

set(CMAKE_CXX_STANDARD 11)

#add_executable(autosetip main.cpp aliyun.cpp)
add_executable(autosetip aliyun.cpp
        encode.h)

if (MINGW)
    set(OPENSSL_ROOT_DIR "C:/msys64/mingw64/")
endif ()

message(STATUS "Using C compiler ${CMAKE_C_COMPILER}, version ${CMAKE_C_COMPILER_VERSION}")
message(STATUS "Using CXX compiler ${CMAKE_CXX_COMPILER}, version ${CMAKE_CXX_COMPILER_VERSION}")

find_package(OpenSSL REQUIRED)
target_link_libraries(autosetip OpenSSL::Crypto)

message(STATUS "Found OpenSSL: ${OPENSSL_SSL_LIBRARY}")
message(STATUS "Found OpenSSL version: ${OPENSSL_VERSION}")

find_package(CURL REQUIRED)
target_link_libraries(autosetip CURL::libcurl)

message(STATUS "Found CURL: ${CURL_LIBRARIES}")
message(STATUS "Found CURL version: ${CURL_VERSION_STRING}")