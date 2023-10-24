//
// Created by gidra on 16.10.23.
//
#include "Player.h"
#include "GameBoard.h"
#include "PlayerController.h"
#include <iostream>
#include "CreatedBoard.h"
#include "Game.h"
#include "InputReader.h"
void Game::StartGame(){
    int level = Game::SelectLevel();
    Player player(100, 0, 100, 0, 0);
    CreatedBoard board(level);
    board.createGameBoard();
    PlayerController controller(player, *board.get_gameboard(0));
    RunGame(board.get_gameboard(0), &player, 0, &board);
}


void Game::EndGame(){
    std::string command;
    std::cout<<"Игра окончена"<<std::endl;
    std::cout<<"Если хотите начать новую игру, введите startgame"<<std::endl;
    std::cout<<"Если хотите выйти, введите stopgame"<<std::endl;
    std::cin>>command;
    if(command == "startgame"){
        this->StartGame();
    }
    else{
        exit(0);
    }
}
int Game::SelectLevel(){
    int level = 0;
    std::cout<<"Введите желаемое количество уровней"<<std::endl;
    std::cin>>level;
    while(level <= 0 || level > 1000) {
        std::cout << "Неверное значение. Введите заново" << std::endl;
        std::cin >> level;
    }
    return level;
}

void Game::CheckWin(Player *player, GameBoard& createdBoard, PlayerController *playerController, int this_level, CreatedBoard* boards){
    if(player->get_X() == createdBoard.getExitX() and player->get_Y() == createdBoard.getExitY()){
        std::cout<<"Поздравляем, вы прошли игру!!";
        std::cout<<"Если хотите перейти на следующий уровень - введите nextlevel, если хотите выйти, введите - stopgame";
        std::string command;
        std::cin>>command;
        if(command == "nextlevel") {
            if (this_level + 1 < boards->get_level()) // предположим, что в CreatedBoard есть функция getNumberofBoards, которая возвращает количество досок
            {
                RunGame(boards->get_gameboard(this_level + 1), player, this_level + 1, boards);
            }
            else
            {
                std::cout << "Вы прошли все уровни! Теперь вы можете начать заново или выйти из игры.";
                EndGame();
            }
        }
        else if(command == "stopgame"){
            EndGame();
        }
        else{
            std::cout<<"Команда не распознана";
        }
    }
}

void Game::CheckLoos(Player& player){
    if(player.get_health() == 0){
        this->EndGame();
    }
}

void Game::RunGame(GameBoard* gameBoard, Player *player, int level, CreatedBoard* boards){
    player->setPosition(0,0);
    PlayerController controller(*player, *gameBoard);
    while(true){
        InputReader inputReader("/home/gidra/CLionProjects/untitled12/Controll");
        inputReader.readInput(*this, &controller);
        // Чтение ввода от пользователя
        // Проверить, победил ли игрок
        CheckWin(player, *gameBoard, &controller, level, boards);
        // Проверить, проиграл ли игрок
        CheckLoos(*player);
        std::cout<<player->get_X()<<player->get_Y();
    }
}

