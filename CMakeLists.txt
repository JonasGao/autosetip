cmake_minimum_required(VERSION 3.28)
project(autosetip LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#add_executable(autosetip main.cpp aliyun.cpp)
add_executable(autosetip aliyun.cpp
        encode.h)

if (MINGW)
    set(OPENSSL_ROOT_DIR "C:/msys64/mingw64/")
endif ()

find_package(OpenSSL REQUIRED)
target_link_libraries(autosetip OpenSSL::Crypto)

find_package(CURL REQUIRED)
target_link_libraries(autosetip CURL::libcurl)