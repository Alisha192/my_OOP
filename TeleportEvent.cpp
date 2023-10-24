//
// Created by gidra on 19.10.23.
//
#include "iostream"
#include "TeleportEvent.h"
#include "GameBoard.h"

void TeleportEvent::event(Player player, GameBoard gameBoard) {
    srand(time(0)); // Инициализация генератора случайных чисел

    int x = rand() % 9; // Случайное число от 0 до 8
    int y = rand() % 9; // Случайное число от 0 до 8
    if(gameBoard.getCell(x, y)->getPassable()){
        std::cout<<"Вы успешно телепортировались";
        player.setPosition(x, y);
    }
    else{
        std::cout<<"Не удалось телепортироваться";
    }

}

TeleportEvent *TeleportEvent::clone() const {
    return new TeleportEvent(*this);
}
