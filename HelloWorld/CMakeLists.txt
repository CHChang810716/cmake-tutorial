cmake_minimum_required (VERSION 3.10) # CMake version check
project (HelloWorld) # Project Name
find_package(Boost REQUIRED COMPONENTS filesystem)

add_library(list_directory src/list_directory.cpp)
target_include_directories(list_directory PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
) # add include directory to target
target_link_libraries(list_directory PUBLIC 
    Boost::filesystem
) # add boost.filesystem

add_executable(hello_world src/hello_world.cpp) # An executable target
target_link_libraries(hello_world list_directory)

include(CMakePackageConfigHelpers)
set(config_install_path lib/cmake/HelloWorld)
configure_package_config_file(
    cmake/Config.cmake.in
    "HelloWorldConfig.cmake"
    INSTALL_DESTINATION ${config_install_path}
)
install(FILES "${CMAKE_BINARY_DIR}/HelloWorldConfig.cmake"
    DESTINATION ${config_install_path}
 )
install( TARGETS hello_world list_directory
    EXPORT HelloWorldTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install( EXPORT HelloWorldTargets
    NAMESPACE HelloWorld::
    DESTINATION ${config_install_path}
)
install(
    DIRECTORY include
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
