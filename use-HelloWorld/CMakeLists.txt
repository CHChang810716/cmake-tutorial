cmake_minimum_required (VERSION 3.10) # CMake version check
project (use-HelloWorld) # Project Name
find_package(HelloWorld CONFIG REQUIRED)
add_executable(use_hello_world src/use_hello_world.cpp) # An executable target
target_link_libraries(use_hello_world HelloWorld::list_directory)