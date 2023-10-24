//
// Created by gidra on 19.10.23.
//

#ifndef UNTITLED12_POSITIVEEVENT_H
#define UNTITLED12_POSITIVEEVENT_H
#include "EventInterface.h"

class PositiveEvent: public EventInterface{
public:
    void event(Player player, GameBoard gameBoard) override;
    [[nodiscard]] PositiveEvent* clone() const override;
};


#endif //UNTITLED12_POSITIVEEVENT_H
