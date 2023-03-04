cmake_minimum_required(VERSION 3.22)
project(Assignment2 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set CIRCULAR_BUFFER_SIZE to the size that the buffer shall be
set(CIRCULAR_BUFFER_SIZE 10)
add_compile_options(-Wall -Wextra -Wpedantic -DBUFFER_SIZE=${CIRCULAR_BUFFER_SIZE})

add_subdirectory(lib)
add_subdirectory(app)