cmake_minimum_required(VERSION 3.26)
project(untitled12)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled12 main.cpp
        Player.cpp
        Player.h
        PlayerController.cpp
        PlayerController.h
        GameBoard.cpp
        GameBoard.h
        GameCell.cpp
        GameCell.h
        CreatedBoard.cpp
        CreatedBoard.h
        InputReader.cpp
        InputReader.h
        Game.cpp
        Game.h
        EventInterface.cpp
        EventInterface.h
        PositiveEvent.cpp
        PositiveEvent.h
        NegativeEvent.cpp
        NegativeEvent.h
        TeleportEvent.cpp
        TeleportEvent.h
        NegativeEvent.cpp
)
