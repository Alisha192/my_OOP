//
// Created by gidra on 12.09.23.
//
#include "Player.h"
#include "iostream"
#include "GameCell.h"
#include "EventInterface.h"
#include "EventInterface.h"
#include "Player.h"
#include "GameBoard.h"

GameCell::GameCell() : isPassable(1) ,Event(nullptr){}
// Метод для установки/изменения проходимости клетки
void GameCell::setPassable(int passable) {
    isPassable = passable;
}

int GameCell::getPassable() {
    return this->isPassable;
}

EventInterface* GameCell::get_event() {
    return Event;
}

void GameCell::set_event(EventInterface *newevent) {
    Event=newevent;
}
void GameCell::triger(Player& player, GameBoard& gameBoard){
    if(Event == nullptr){
        return;
    }
    Event->event(player, gameBoard);
}
