# CUDA support introduced in version 3.8
cmake_minimum_required(VERSION 3.8)

# For CUDA
project(proj3 LANGUAGES CXX CUDA)

# Sources/library to build
include_directories(include)
set(SOURCES src/vsq.cu src/cuda_buffer.cu src/transvsq.cu)
add_library(proj3 SHARED ${SOURCES})

# For CUDA
target_compile_features(proj3 PUBLIC cxx_std_14)
target_link_libraries(proj3 PUBLIC cufft_static culibos)
set_target_properties(proj3 PROPERTIES CUDA_SEPARABLE_CONDITION ON)

# For pybind11
set_property(TARGET proj3 PROPERTY POSITION_INDEPENDENT_CODE ON)

install(TARGETS proj3 DESTINATION .)
