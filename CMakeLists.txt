cmake_minimum_required(VERSION 3.20)
project(untitled) # testproject — название проекта, нужно везде заменить на своё

set(CMAKE_CXX_STANDARD 14) # версия плюсов
set(CMAKE_CXX_COMPILER clang++)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang\$")
    set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/usr/local/opt/libomp/include")
    set(OpenMP_CXX_LIB_NAMES "omp")
    set(OpenMP_omp_LIBRARY "/usr/local/opt/libomp/lib/libomp.dylib")
endif ()

find_package(OpenMP REQUIRED)

add_executable(untitled no11.cpp)
target_link_libraries(untitled PRIVATE OpenMP::OpenMP_CXX)