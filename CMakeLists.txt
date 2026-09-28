cmake_minimum_required(VERSION 3.10)

project(parking-lot-system VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Headers
include_directories(include)

# Collect future sources from src/ (currently empty skeleton)
file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(parking-lot-system main.cpp ${SRC_FILES})

target_include_directories(parking-lot-system PRIVATE include)
