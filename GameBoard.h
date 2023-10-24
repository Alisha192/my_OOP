#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameCell.h"
#include <vector>
class GameBoard {
private:
    GameBoard(GameBoard &&other) noexcept ;

    int width; // Ширина поля
    int height; // Высота поля
    GameCell** cells; // Двумерный массив клеток
    int entranceX; // Координаты входа по оси X
    int entranceY; // Координаты входа по оси Y
    int exitX; // Координаты выхода по оси X
    int exitY; // Координаты выхода по оси Y
public:
    // Конструктор с параметрами для создания игрового поля
    GameBoard(int w, int h, int entranceX, int entranceY, int exitX, int exitY);

    // Деструктор для освобождения памяти
    ~GameBoard();

    // Метод для получения клетки по координатам
    GameCell* getCell(int x, int y);

    // Метод для получения координат входа
    [[nodiscard]] int getEntranceX() const;

    [[nodiscard]] int getEntranceY() const;
    GameBoard& operator=(const GameBoard& other) noexcept;
    GameBoard(const GameBoard& other) noexcept;
        // Метод для получения координат выхода
    [[nodiscard]] int getExitX() const;
    GameBoard& operator=(GameBoard&& other) noexcept;

    [[nodiscard]] int getExitY() const;
    [[nodiscard]] int getWidth() const ;
    [[nodiscard]] int getHeight() const ;

    void generateMaze();
    void DFS(int x, int y);
    void placeRandomEvents();
};

#endif // GAMEBOARD_H