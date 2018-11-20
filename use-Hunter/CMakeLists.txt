cmake_minimum_required (VERSION 3.10) # CMake version check
include(cmake/HunterGate.cmake)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.49.tar.gz"
    SHA1 "777200954f3851322932f67c782fe92990b32ab2"
)
project (use-Hunter) # Project Name
hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)