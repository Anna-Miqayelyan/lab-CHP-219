# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(UDPClientServerProject)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add executable target (MainClient and MainServer)
add_executable(MainClient src/MainClient.cpp src/UDPSocket.cpp src/UDPServer.cpp)
add_executable(MainServer src/MainServer.cpp src/UDPSocket.cpp src/UDPServer.cpp)

# Include the header files
target_include_directories(MainClient PRIVATE src)
target_include_directories(MainServer PRIVATE src)

# Link necessary libraries (like Winsock for Windows)
if(WIN32)
    target_link_libraries(MainClient ws2_32)
    target_link_libraries(MainServer ws2_32)
endif()