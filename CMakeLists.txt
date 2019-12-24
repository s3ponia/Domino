cmake_minimum_required(VERSION 3.15)
project(Domino)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
set(CMAKE_BUILD_TYPE Debug)

add_executable(Domino
        src/main.cpp
        src/cpp/DominoBlock.cpp
        src/cpp/Board.cpp
        src/cpp/Computer.cpp
        src/cpp/Boneyard.cpp
        src/cpp/RealPlayer.cpp
        src/cpp/Game.cpp
        src/cpp/UIRealPlayer.cpp
        src/cpp/UIComputer.cpp
        src/cpp/UIModel.cpp
        src/cpp/GameBuilder.cpp
        src/cpp/IPlayer.cpp
        )
target_link_libraries(Domino ${CURSES_LIBRARIES})