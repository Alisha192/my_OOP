//
// Created by gidra on 12.09.23.
//

#include "Player.h"
//
// Created by gidra on 12.09.23.
//
Player::Player(int max_hp, int score, int health, int X, int Y) : health(health), X(X), Y(Y) {
    set_health(max_hp);
    set_max_hp(max_hp);
    setPosition(X, Y);
    set_score(0);
    set_maxScore(1000);
}
[[nodiscard]] int Player::get_health() const{
    return this->health;
}
[[nodiscard]] int Player::get_score() const {
    return this->score;
}

void Player::set_health(int n_health){
    if(n_health>=0){this->health= n_health;}
}
void Player::set_score(int n_score){
    if(n_score>=0){this->score= n_score;}
}

void Player::set_maxScore(int n_score){
    if(n_score>=0){this->maxScore= n_score;}
}
void Player::set_max_hp(int max_hp) {
    if(max_hp>=0){
        this->maxHealth = max_hp;
    }
}
int Player::get_X() const {
    return this->X;
}
int Player::get_Y() const{
    return this->Y;
}
void Player::setPosition(int new_x, int new_y) {
    this->X = new_x;
    this->Y = new_y;
}