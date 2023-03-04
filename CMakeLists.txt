cmake_minimum_required(VERSION 3.22)
project(algo_ds)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    src/sort/merge_sort.cpp
    src/sort/quick_sort.cpp
    src/sort/heap_sort.cpp
    src/sort/tion_sort.cpp
    src/sort/bubble_sort.cpp
    src/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${CMAKE_PROJECT_NAME}
    PRIVATE
    src/sort/include
    src/util
)