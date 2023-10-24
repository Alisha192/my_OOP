//
// Created by gidra on 19.10.23.
//
#include "PositiveEvent.h"
#include "Player.h"
#include "iostream"
#include "GameBoard.h"
void PositiveEvent::event(Player player, GameBoard gameBoard) {
    std::cout<<"Вы нашли аптечку";
    if(player.get_health()<MAX_HP) {
        player.set_health(player.get_health() + N);
    }
}

PositiveEvent *PositiveEvent::clone() const {
    return new PositiveEvent(*this);
}
