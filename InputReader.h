//
// Created by gidra on 16.10.23.
//

#ifndef UNTITLED10_INPUTREADER_H
#define UNTITLED10_INPUTREADER_H
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Game.h"
#include "PlayerController.h"
enum class Action {
    moveUp, moveDown, moveLeft, moveRight, startGame, endGame
};
class InputReader {
public:
    explicit InputReader(const std::string& controlFile);
    using ControlMap = std::unordered_map<char, Action> ;

    ControlMap controlMap_;

    void readInput(Game &game, PlayerController *playerController);

private:

    // Загрузка клавиш управления из файла
    void loadControls(const std::string& controlFile);

};


#endif //UNTITLED10_INPUTREADER_H
