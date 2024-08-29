cmake_minimum_required(VERSION 3.10)
project(MockDataGenerator)

set(CMAKE_CXX_STANDARD 17)

# MySQL Connector C++ paths
include_directories(/usr/include/mysqlx)
link_directories(/usr/lib)

# Add executable
add_executable(MockDataGenerator src/main.cpp)

# Link MySQL Connector C++ library
target_link_libraries(MockDataGenerator mysqlcppconn8)
