cmake_minimum_required(VERSION 3.10)

# Set project name and C++ language
project(CPP-JSON LANGUAGES CXX)

# Specify the C++ compiler
set(CMAKE_CXX_COMPILER g++) # Change this to your preferred compiler (e.g., clang++)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add header files (not necessary for compilation, but useful for clarity)
set(HEADER_FILES
    headers/json.h
)

# Add source files
set(SOURCE_FILES
    src/json.cpp
)

# Create the executable


# Create the library
add_library(CPP-JSON SHARED ${SOURCE_FILES} ${HEADER_FILES})

# Include directories for headers
target_include_directories(CPP-JSON PRIVATE headers)