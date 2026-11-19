cmake_minimum_required(VERSION 3.10.0)
project(it-simulation-system VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(it-simulation-system
	main.cpp
	lib/App.cpp
    lib/DynamicArray.cpp
	lib/LinkedList.cpp
)

target_include_directories(it-simulation-system PRIVATE include)


# ==================== TESTS =====================


enable_testing()

add_executable(LinkedList tests/LinkedList.cpp lib/LinkedList.cpp)
target_include_directories(LinkedList PRIVATE include)
add_test(NAME LinkedList COMMAND $<TARGET_FILE:LinkedList>)

add_executable(DynamicArray tests/DynamicArray.cpp)
target_include_directories(DynamicArray PRIVATE include)
add_test(NAME DynamicArray COMMAND $<TARGET_FILE:DynamicArray>)

add_executable(ConfigLoader tests/ConfigLoader.cpp lib/ConfigLoader.cpp)
target_include_directories(ConfigLoader PRIVATE include)

configure_file(
	tests/test_input.txt
	${CMAKE_CURRENT_BINARY_DIR}/test_input.txt
	COPYONLY
)

add_test(NAME ConfigLoader COMMAND $<TARGET_FILE:ConfigLoader>)
set_tests_properties(ConfigLoader PROPERTIES
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
