//
// Created by gidra on 12.09.23.
//
#ifndef UNTITLED10_PLAYER_H
#define UNTITLED10_PLAYER_H


class Player {
private:
    int health{};
    int X;
    int Y;
    int maxHealth{};
    int score{};
    int maxScore{};
public:
    Player(int max_hp, int score, int health, int X, int Y);
    [[nodiscard]] int get_health() const;
    [[nodiscard]] int get_score() const;
    [[nodiscard]] int get_X() const;
    [[nodiscard]] int get_Y() const;
    void setPosition(int new_x, int new_y);
    void set_health(int n_health);
    void set_score(int n_score);
    void set_maxScore(int n_score);
    void set_max_hp(int max_hp);
};

#endif //UNTITLED10_PLAYER_H