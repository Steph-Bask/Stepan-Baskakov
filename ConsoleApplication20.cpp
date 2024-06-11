#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

const int SIZE = 10;

enum Cell {
    EMPTY, SHIP, HIT, MISS
};

typedef std::vector<std::vector<Cell>> Board;

void InitializeBoard(Board& board) {
    board.resize(SIZE, std::vector<Cell>(SIZE, EMPTY));
}

void PrintBoard(const Board& board) {
    std::cout << "  ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            switch (board[i][j]) {
            case EMPTY: std::cout << ". "; break;
            case SHIP: std::cout << "S "; break;
            case HIT: std::cout << "X "; break;
            case MISS: std::cout << "O "; break;
            }
        }
        std::cout << std::endl;
    }
}

void PlaceShips(Board& board) {
    srand(time(0));
    for (int i = 0; i < 5; ++i) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        board[x][y] = SHIP;
    }
}

bool Attack(Board& board, int x, int y) {
    if (board[x][y] == SHIP) {
        board[x][y] = HIT;
        return true;
    }
    else {
        board[x][y] = MISS;
        return false;
    }
}

int main() {
    Board board;
    InitializeBoard(board);
    PlaceShips(board);

    int x, y;
    while (true) {
        PrintBoard(board);
        std::cout << "Введите координаты атаки (x y): ";
        std::cin >> x >> y;

        if (!Attack(board, x, y)) {
            std::cout << "Мимо!" << std::endl;
        }
        else {
            std::cout << "Попадание!" << std::endl;
        }
    }

    return 0;
}