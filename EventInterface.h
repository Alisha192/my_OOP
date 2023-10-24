//
// Created by gidra on 19.10.23.
//

#ifndef UNTITLED12_EVENTINTERFACE_H
#define UNTITLED12_EVENTINTERFACE_H
#define N 20
#define MAX_HP 100
#include "Player.h"
class GameBoard;
class EventInterface {
public:
    virtual void event(Player player, GameBoard gameBoard)=0;
    virtual ~EventInterface() = default;
    virtual EventInterface* clone() const = 0;
};


#endif //UNTITLED12_EVENTINTERFACE_H
