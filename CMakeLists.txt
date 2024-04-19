cmake_minimum_required(VERSION 3.28)
project(autosetip LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(autosetip main.cpp)

if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
    set(BUILD_SHARED_LIBS OFF)
    set(BUILD_STATIC_LIBS ON)
    set(BUILD_STATIC_CURL ON)

    target_link_libraries(autosetip CURL::libcurl)
    target_compile_definitions(autosetip PUBLIC -DCURL_STATICLIB)

    message(STATUS "Fetching CURL")
    include(FetchContent)
    FetchContent_Declare(
            CURL
            GIT_REPOSITORY https://github.com/curl/curl.git
    )
    FetchContent_MakeAvailable(CURL)
    message(STATUS "Found CURL source dir: ${CURL_SOURCE_DIR}")
    message(STATUS "Found CURL binary dir: ${CURL_BINARY_DIR}")
else ()
    find_package(CURL REQUIRED)
    include_directories(${CURL_INCLUDE_DIR})
    target_link_libraries(autosetip ${CURL_LIBRARIES})
endif ()