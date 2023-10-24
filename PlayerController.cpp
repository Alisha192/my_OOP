//
// Created by gidra on 12.09.23.
//
#include "GameBoard.h"
#include "iostream"
#include "PlayerController.h"
void PlayerController::move(Direction direction) {
    int currentX = player.get_X();
    int currentY = player.get_Y();

    // Вычисляем новые координаты в зависимости от направления
    int newX = currentX;
    int newY = currentY;

    if (direction == Direction::up) {
        newY--;
    } else if (direction == Direction::down) {
        newY++;
    } else if (direction == Direction::left) {
        newX--;
    } else if (direction == Direction::right) {
        newX++;
    }

    // Проверка на выход за границы поля и проходимость клетки
    if (newX >= 0 && newX < gameBoard.getWidth() &&
        newY >= 0 && newY < gameBoard.getHeight() &&
        gameBoard.getCell(newX, newY)->getPassable()) {
        // Если клетка проходима, перемещаем игрока
        player.setPosition(newX, newY);
        gameBoard.getCell(newX, newY)->triger(player, gameBoard);
    }else {
            std::cout << "Невозможно двигаться в этом направлении или клетка непроходима." << std::endl;
        }
}

PlayerController::PlayerController(Player& player, GameBoard& gameBoard) : player(player), gameBoard(gameBoard) {}






