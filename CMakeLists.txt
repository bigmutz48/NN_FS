cmake_minimum_required(VERSION 3.18)
project(MyCudaProject LANGUAGES C CXX CUDA)

# Gather all your source files; adjust the glob if needed
file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/*.cu"
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

# Define the executable target
add_executable(my_cuda_exe ${SRC_FILES})

# Tell CMake where to find CUDA headers
target_include_directories(my_cuda_exe PRIVATE
    /usr/local/cuda/include
)

# Link against CUDA runtime libraries
target_link_libraries(my_cuda_exe PRIVATE
    cuda
    cudart
)
