cmake_minimum_required(VERSION 3.10)
project(tutorial VERSION 0.1 LANGUAGES CXX)

set(${PROJECT_NAME}_DATA ${CMAKE_SOURCE_DIR}/data CACHE PATH "all data and sources")
set(THIRDPARTIES_PATH ${CMAKE_SOURCE_DIR}/thirdparty CACHE PATH "3td")

# profiling with gprof
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
# SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
# SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg") 

message(STATUS, "project name ${PROJECT_NAME}")
# in-source build: CMAKE_SOURCE_DIR=CMAKE_BINARY_DIR
configure_file("${CMAKE_SOURCE_DIR}/build_config/config.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h") 

add_executable(${PROJECT_NAME} ./src/tutorial.cpp)  # all source file
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
# EXCLUDE_FROM_ALL

# macro and functions
macro(set_my_variable _INPUT)
  if("${_INPUT}" STREQUAL "Foo")
    set(my_output_variable "foo")
  else()
    set(my_output_variable "bar")
  endif()
endmacro(set_my_variable)

set_my_variable("Foo")
message(STATUS ${my_output_variable})

# enable_testing() # use CTest extension
# add_executable(tutorial_test ./test/first_test.cpp) # GoogleTest, Boost.Test, QtTest or whatever framework you use
# # depending on the framework, you need to link to it
# target_link_libraries(tutorial_test gtest_main)

# TODO: use valgrind: https://stackoverflow.com/questions/40325957/how-do-i-add-valgrind-tests-to-my-cmake-test-target
# enable_testing() # use CTest extension
# GoogleTest  https://cmake.org/cmake/help/v3.9/module/GoogleTest.html
# add_executable(tutorial_test ./test/first_test.cpp) # GoogleTest, Boost.Test, QtTest or whatever framework you use
# # depending on the framework, you need to link to it
# target_link_libraries(tutorial_test gtest_main)
# add_test(NAME tutorial_test COMMAND tutorial_test)

# package and distribute
set(CPACK_PACKAGE_NAME "tutorial_")
set(CPACK_GENERATOR "7Z")
include(CPack)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin)

