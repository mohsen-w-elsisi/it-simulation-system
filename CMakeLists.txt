cmake_minimum_required(VERSION 3.10.0)
project(it-simulation-system VERSION 0.1.0 LANGUAGES C CXX)

add_executable(it-simulation-system main.cpp)

enable_testing()

add_executable(LinkedList tests/LinkedList.cpp)
add_test(NAME LinkedList COMMAND $<TARGET_FILE:LinkedList>)
