//
// Created by gidra on 19.10.23.
//

#ifndef UNTITLED12_TELEPORTEVENT_H
#define UNTITLED12_TELEPORTEVENT_H
#include "EventInterface.h"

class TeleportEvent: public EventInterface{
public:
    void event(Player player, GameBoard gameBoard) override;
    TeleportEvent* clone() const override;
};


#endif //UNTITLED12_TELEPORTEVENT_H
