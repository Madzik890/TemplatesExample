# CMakeLists.txt

# CMake version that the current computer is using
cmake_minimum_required(VERSION "3.22")

# name of the project
project(templates)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_OSX_DEPLOYMENT_TARGET 13.0)

# set working directory
set(SOURCE_DIR src)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# specify the executable target to be built
add_executable(${PROJECT_NAME} 
                    src/main.cpp)

target_link_libraries(${PROJECT_NAME} )