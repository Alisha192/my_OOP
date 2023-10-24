//
// Created by gidra on 12.09.23.
//
#include "iostream"
#ifndef UNTITLED10_GAMECELL_H
#define UNTITLED10_GAMECELL_H
#include "EventInterface.h"

class GameCell {
private:
    int isPassable;
    EventInterface* Event;
public:
    // Конструктор с параметром для установки проходимости клетки и события
    explicit GameCell();

    // Метод для установки/изменения проходимости клетки
    void setPassable(int passable);

    int getPassable();
    EventInterface* get_event();
    void set_event(EventInterface* event);
    void triger(Player& player, GameBoard& gameBoard);

};

#endif //UNTITLED10_GAMECELL_H