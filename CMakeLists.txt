cmake_minimum_required(VERSION 3.16.3)
project(MD5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CPU_OPTIONS -Werror -Wall -Wextra -pedantic -ffunction-sections -fdata-sections -Ofast -std=c++17 -lpthread -lssl -lcrypto)
add_compile_options(${CPU_OPTIONS})

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

add_subdirectory(firmware)
add_subdirectory(crack)
add_subdirectory(threads)
