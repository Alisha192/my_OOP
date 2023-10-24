//
// Created by gidra on 16.10.23.
//

#ifndef UNTITLED10_GAME_H
#define UNTITLED10_GAME_H

#include "Player.h"
#include "PlayerController.h"
#include "CreatedBoard.h"

class Game {
public:
    void StartGame();
    void changeLvl(int level);
    void EndGame();
    static int SelectLevel();
    void CheckLoos(Player &player);
    void RunGame(GameBoard* gameBoard, Player *player, int level, CreatedBoard *boards);
    void CheckWin(Player *player, GameBoard &createdBoard, PlayerController *playerController, int this_level,
                  CreatedBoard *boards);
};


#endif //UNTITLED10_GAME_H
