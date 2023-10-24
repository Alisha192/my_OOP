//
// Created by gidra on 14.10.23.
//

#ifndef UNTITLED10_CREATEDBOARD_H
#define UNTITLED10_CREATEDBOARD_H
#include "GameBoard.h"

class CreatedBoard {
    int level;
    GameBoard** gameBoards;
public:
    void createGameBoard();
    ~CreatedBoard();
    explicit CreatedBoard(int lvl);
    void set_level(int new_level);
    GameBoard* get_gameboard(int lvl);
    [[nodiscard]] int get_level() const;
};


#endif //UNTITLED10_CREATEDBOARD_H
