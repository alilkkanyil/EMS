cmake_minimum_required(VERSION 3.15)
project(EMS VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Find required packages
find_package(Boost REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

# Collect all source files
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Add the executable
add_executable(ems ${SRC_FILES})

# Link libraries
target_link_libraries(ems
    PRIVATE
    Boost::boost
    gRPC::grpc
    gRPC::grpc++
    protobuf::libprotobuf
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    GTest::gtest
    GTest::gtest_main
)

# Include directories
target_include_directories(ems PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Add compiler warnings
if(MSVC)
    target_compile_options(ems PRIVATE /W4)
else()
    target_compile_options(ems PRIVATE -Wall -Wextra -Wpedantic)
endif()