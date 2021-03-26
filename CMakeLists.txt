cmake_minimum_required(VERSION 3.17)
project(learn_c C)

set(CMAKE_C_STANDARD 11)

aux_source_directory(. DIR_SRCS)

add_executable(learn_c ${DIR_SRCS})

enable_testing()
add_test(test_1 learn_c)
