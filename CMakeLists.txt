cmake_minimum_required(VERSION 3.29)
project(gmpwrap)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(GMP REQUIRED)

add_library(gmpwrap SHARED
        src/gmpwrap.h
        src/types/BigFloat.h
        src/types/BigInteger.h
        src/types/BigFloat.cpp
        src/types/BigInteger.cpp
)
target_link_libraries(gmpwrap PUBLIC ${GMP_LIBRARIES})
target_include_directories(gmpwrap PUBLIC ${GMP_INCLUDES} .)
target_include_directories(gmpwrap PUBLIC src)

add_executable(gmpwrap_test
        tests/all_tests.cpp
        tests/test_big_integer.cpp
)
target_include_directories(gmpwrap_test PUBLIC src)
target_link_libraries(gmpwrap_test PUBLIC gmpwrap)

find_package(GTest REQUIRED)
target_link_libraries(gmpwrap_test PUBLIC GTest::gtest GTest::gtest_main)
