cmake_minimum_required(VERSION 3.10)
project(api_differentiator_tool)

set(CMAKE_CXX_STANDARD 17)

# Clang and MySQL connector libraries
find_package(Clang REQUIRED)
include_directories(${CLANG_INCLUDE_DIRS})
link_directories(${CLANG_LIBRARY_DIRS})

include_directories(include) # For MySQL connector

add_executable(api_differentiator_tool src/main.cpp src/ApiDifferentiator.cpp src/DatabaseManager.cpp)

# Link with Clang and MySQL libraries
target_link_libraries(api_differentiator_tool ${CLANG_LIBRARIES} mysqlcppconn)
    