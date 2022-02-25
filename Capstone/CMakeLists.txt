cmake_minimum_required(VERSION 3.11.3)

# set(CMAKE_CXX_STANDARD 17)
project(Capstone)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

# Add project executable
add_executable(Capstone ${project_SRCS})

# For finding our SDL2 package
INCLUDE(FindPkgConfig)
# Searching SDL2 packages
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)
# Including our external library's directory for header files
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
# Linking SDL2 library with our project
target_link_libraries(Capstone ${SDL2_LIBRARIES})

