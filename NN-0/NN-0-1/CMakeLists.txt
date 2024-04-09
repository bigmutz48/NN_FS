#this is the CMakeLists.txt file for NN_FS-0-1



#set the project name and version!
project(NeuralNet_FS VERSION 0.0)


#specify c++ standard

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(NeuralNet_FS main.cpp initialize.cpp)


#include necessary directories!
target_include_directories(NeuralNet_FS PUBLIC
    "${PROJECT_BINARY_DIR}"# still have no idea what is going on here .....
  )
