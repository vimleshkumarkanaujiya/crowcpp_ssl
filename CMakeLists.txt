cmake_minimum_required(VERSION 3.15)

project(Main)

find_package(OpenSSL REQUIRED)

set(INCLUDE_PATHS boost_1_83_0 crow/include)

set(CROW_FEATURES "ssl")

add_executable(Main main.cpp)

target_include_directories(Main PUBLIC ${INCLUDE_PATHS})

target_link_libraries(Main PRIVATE OpenSSL::SSL OpenSSL::Crypto)