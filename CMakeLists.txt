cmake_minimum_required(VERSION 3.10.0)
project(it-simulation-system VERSION 0.1.0 LANGUAGES C CXX)

# Use a modern compiler-agnostic c++ standard 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# =================== Compiling Lib ===================

# find source files in the lib directory
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp"
)

# Compile the files
add_library(it_simulation_objects OBJECT ${LIB_SOURCES})
set_target_properties(it_simulation_objects PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(it_simulation_objects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add staticaly linked library for the main executable
add_library(it_simulation_static STATIC
    $<TARGET_OBJECTS:it_simulation_objects>
)
target_link_libraries(it_simulation_static PUBLIC it_simulation_objects)

# add shared library for the tests
add_library(it_simulation_shared SHARED
    $<TARGET_OBJECTS:it_simulation_objects>
)
target_link_libraries(it_simulation_shared PUBLIC it_simulation_objects)


# =================== Main Executable ===================

add_executable(it-simulation-system main.cpp)
target_link_libraries(it-simulation-system PRIVATE it_simulation_static)
set_target_properties(it-simulation-system PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app"
)


# ==================== Tests =====================

enable_testing()

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
)

foreach(TEST_SOURCE IN LISTS TEST_SOURCES)
    get_filename_component(TEST_NAME "${TEST_SOURCE}" NAME_WE)

    add_executable(${TEST_NAME}Test ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME}Test PRIVATE it_simulation_shared)
    set_target_properties(${TEST_NAME}Test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
    )

    add_test(
        NAME ${TEST_NAME}
        COMMAND $<TARGET_FILE:${TEST_NAME}Test>
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
    )
endforeach()

file(COPY
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/testAssets"
    DESTINATION
        "${CMAKE_CURRENT_BINARY_DIR}/tests"
)
