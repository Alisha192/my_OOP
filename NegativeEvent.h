//
// Created by gidra on 19.10.23.
//

#ifndef UNTITLED12_NEGATIVEEVENT_H
#define UNTITLED12_NEGATIVEEVENT_H
#include "EventInterface.h"

class NegativeEvent: public EventInterface  {
public:
    void event(Player player, GameBoard gameBoard) override;
    NegativeEvent* clone() const override;
};


#endif //UNTITLED12_NEGATIVEEVENT_H
