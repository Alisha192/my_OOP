//
// Created by gidra on 19.10.23.
//

#include <limits>
#include "NegativeEvent.h"
#include "iostream"
#include "GameBoard.h"
void NegativeEvent::event(Player player, GameBoard gameBoard) {
    std::cout << "Вы упали в яму" << std::endl;
    player.set_health(player.get_health() - N);
    std::cout << player.get_health() << "-Ваше здоровье" << std::endl;
    std::cout << "Перед собой вы видете две лестницы, какую выберете?";

    int c;
    while (true) {
        std::cout << "1 или 2?";
        std::cin >> c;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Было введено не числовое значение. Попробуйте ещё раз.\n";
        } else {
            break;
        }
    }

    if (c != 1) {
        std::cout << "Вы упали обратно яму";
        player.set_health(player.get_health() - N);
        std::cout << player.get_health() << "-Ваше здоровье";
    }
}

NegativeEvent *NegativeEvent::clone() const {
    return new NegativeEvent(*this);
}
