#include "iostream"
#include "CreatedBoard.h"
CreatedBoard::CreatedBoard(int lvl) : level(lvl) {
    gameBoards = new GameBoard*[lvl];
}


CreatedBoard::~CreatedBoard() {
    for (int i = 0; i < level; ++i) {
        delete gameBoards[i];
    }
    delete[] gameBoards;
}

int CreatedBoard::get_level() const {
    return this->level;
}

void CreatedBoard::set_level(int new_level) {
    this->level = new_level;
}

GameBoard * CreatedBoard::get_gameboard(int lvl){
    return gameBoards[lvl];
}

void CreatedBoard::createGameBoard() {
    for (int i = 0; i < level; ++i) {
        gameBoards[i] = new GameBoard(10, 10, 0, 0, 8, 8);
        gameBoards[i]->generateMaze();
    }
}