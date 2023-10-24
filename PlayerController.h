//
// Created by gidra on 12.09.23.
//

#ifndef UNTITLED10_PLAYERCONTROLLER_H
#define UNTITLED10_PLAYERCONTROLLER_H
#include "string"
#include "Player.h"
#include "GameBoard.h"
#include "EventInterface.h"
enum class Direction{up, down, left, right};
class PlayerController {
private:

    Player& player;
    GameBoard& gameBoard;

public:
    PlayerController(Player &player, GameBoard& gameBoard);
    void move(Direction direction);

};


#endif //UNTITLED10_PLAYERCONTROLLER_H