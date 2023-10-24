#include <vector>
#include <algorithm>
#include <random>
#include "GameBoard.h"
#include "iostream"
#include "PositiveEvent.h"
#include "NegativeEvent.h"
#include "TeleportEvent.h"

// Конструктор с параметрами для создания игрового поля
GameBoard::GameBoard(int w, int h, int entranceX, int entranceY, int exitX, int exitY) : width(w), height(h), entranceX(entranceX), entranceY(entranceY), exitX(exitX), exitY(exitY) {
    // Выделение памяти под массив клеток
    if (w <= 0 || h <= 0) {
        throw std::invalid_argument("Width and height must be positive.");
    }
    width = w;
    height = h;
    cells = new GameCell*[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new GameCell[width];
    }
}

// Деструктор для освобождения памяти
GameBoard::~GameBoard() {
    // Освобождение памяти, выделенной под клетки
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(cells[i][j].get_event() != nullptr) {
                //delete cells[i][j].get_event();
            }
        }
        delete[] cells[i];
    }
    delete[] cells;
}
// Конструктор копирования
GameBoard::GameBoard(const GameBoard& other) noexcept: width(other.width), height(other.height), entranceX(other.entranceX), entranceY(other.entranceY), exitX(other.exitX), exitY(other.exitY) {
    cells = new GameCell*[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new GameCell[width];
        for (int j = 0; j < width; ++j) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

// Оператор присваивания копированием
GameBoard& GameBoard::operator=(const GameBoard& other) noexcept {
    if (this != &other) {
        // Don't forget to delete the previously held events
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                delete cells[i][j].get_event();
            }
            delete[] cells[i];
        }
        delete[] cells;

        width = other.width;
        height = other.height;
        entranceX = other.entranceX;
        entranceY = other.entranceY;
        exitX = other.exitX;
        exitY = other.exitY;

        cells = new GameCell*[height];
        for (int i = 0; i < height; ++i) {
            cells[i] = new GameCell[width];
            for (int j = 0; j < width; ++j) {
                cells[i][j] = other.cells[i][j];
                if(other.cells[i][j].get_event()){
                    cells[i][j].set_event(other.cells[i][j].get_event()->clone());
                }
            }
        }
    }
    return *this;
}

// Конструктор перемещения
GameBoard::GameBoard(GameBoard&& other) noexcept : width(other.width), height(other.height), entranceX(other.entranceX), entranceY(other.entranceY), exitX(other.exitX), exitY(other.exitY), cells(other.cells) {
    other.cells = nullptr;
    other.width = 0;
    other.height = 0;
}

// Оператор присваивания перемещением
GameBoard& GameBoard::operator=(GameBoard&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < height; ++i) {
            delete[] cells[i];
        }
        delete[] cells;

        width = other.width;
        height = other.height;
        entranceX = other.entranceX;
        entranceY = other.entranceY;
        exitX = other.exitX;
        exitY = other.exitY;
        cells = other.cells;

        other.width = 0;
        other.height = 0;
        other.cells = nullptr;
    }
    return *this;
}


// Метод для получения клетки по координатам
GameCell* GameBoard::getCell(int x, int y) {
    return &cells[y][x];
}
void GameBoard::placeRandomEvents() {
    // Используем <random> для генерации случайных чисел
    std::mt19937 rng(std::random_device{}());
    int event_chance = 10; // С шансом в 10% добавить событие в каждую клетку
    std::uniform_int_distribution<int> percent_dist(0, 99); // Распределение для вычисления шансов
    std::uniform_int_distribution<int> event_type_dist(0, 2); // Распределение для определения типа события

    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            // С шансом в 10% добавляем событие
            if(percent_dist(rng) < event_chance) {
                EventInterface* event = nullptr;
                switch (event_type_dist(rng)) {
                    case 0:
                        event = new PositiveEvent;
                        break;
                    case 1:
                        event = new NegativeEvent;
                        break;
                    case 2:
                        event = new TeleportEvent;
                        break;
                    default:
                        break;
                }
                if (event != nullptr) {
                    // Удаляем старое событие, если оно есть
                    if (cells[j][i].get_event() != nullptr) {
                        delete cells[j][i].get_event();
                    }
                    // Присваиваем новое событие
                    cells[i][j].set_event(event);
                    std::cout<<j<<i<<std::endl;
                }
            }
        }
    }
}


// Метод для получения координат входа
int GameBoard::getEntranceX() const {
    return entranceX;
}

int GameBoard::getEntranceY() const {
    return entranceY;
}

// Метод для получения координат выхода
int GameBoard::getExitX() const {
    return exitX;
}

int GameBoard::getExitY() const {
    return exitY;

}
int GameBoard::getWidth() const {
    return this->width;
}
int GameBoard::getHeight() const{
    return this->height;
}
void GameBoard::DFS(int x, int y) {
    // делаем текущую клетку проходимой
    cells[x][y].setPassable(1);

    // список всех возможных направлений перемещения
    std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // перемешиваем направления, чтобы генерация была случайной
    std::shuffle(directions.begin(), directions.end(), std::mt19937(std::random_device()()));

    // проверяем каждое направление
    for (const auto& dir : directions) {
        // вычисляем координаты следующей клетки
        int newX = x + dir.first * 2;
        int newY = y + dir.second * 2;

        // проверяем, находятся ли новые координаты внутри поля и является ли следующая клетка непроходимой
        if (newX >= 0 && newX < width && newY >= 0 && newY < height && !cells[newX][newY].getPassable()) {
            // делаем промежуточную клетку проходимой
            cells[x + dir.first][y + dir.second].setPassable(1);
            // продолжаем DFS из новой клетки
            DFS(newX, newY);
        }
    }
}
void GameBoard::generateMaze() {
    // сначала сделаем все клетки непроходимыми
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            cells[j][i].setPassable(0);
        }
    }

    // запуск DFS из точки входа
    DFS(entranceX, entranceY);
    placeRandomEvents();
}