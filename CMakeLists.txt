cmake_minimum_required(VERSION 3.15)
project(Domino)

set(CMAKE_CXX_STANDARD 14)

add_executable(Domino
        src/main.cpp
        src/cpp/DominoBlock.cpp
        src/cpp/Board.cpp
        src/cpp/Computer.cpp
        src/cpp/Boneyard.cpp
        src/cpp/RealPlayer.cpp
        src/cpp/Game.cpp
        )