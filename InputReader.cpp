//
// Created by gidra on 16.10.23.
//
#include "PlayerController.h"
#include "InputReader.h"
void InputReader::loadControls(const std::string& controlFile) {
    std::ifstream file(controlFile);
    if (!file.is_open()) {
        std::cerr << "Failed to open control file" << std::endl;
        return;
    }

    char key;
    std::string command;

    while (file >> key >> command) {
        if (command == "moveUp")
            controlMap_[key] = Action::moveUp;
        else if (command == "moveDown")
            controlMap_[key] = Action::moveDown;
        else if (command == "moveLeft")
            controlMap_[key] = Action::moveLeft;
        else if (command == "moveRight")
            controlMap_[key] = Action::moveRight;
        else if (command == "startGame")
            controlMap_[key] = Action::startGame;
        else if (command == "endGame")
            controlMap_[key] = Action::endGame;
    }

    file.close();
}
InputReader::InputReader(const std::string& controlFile) {
    loadControls(controlFile);
}

// Считывание команды с клавиатуры
void InputReader::readInput(Game& game, PlayerController *playerController) {
    char input;
    std::cin >> input;

    auto it = controlMap_.find(input);
    if (it != controlMap_.end()) {
        switch(it->second) {
            case Action::moveUp:
                playerController->move(Direction::up);
                break;
            case Action::moveDown:
                playerController->move(Direction::down);
                break;
            case Action::moveLeft:
                playerController->move(Direction::left);
                break;
            case Action::moveRight:
                playerController->move(Direction::right);
                break;
            case Action::startGame:
                game.StartGame();
                break;
            case Action::endGame:
                game.EndGame();
                break;
            default:
                break;
        }
    }
}
