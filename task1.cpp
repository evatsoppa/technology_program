#include <iostream>
#include <vector>

using namespace std;

// ходы для ладьи 
vector<pair<int, int>> rookMoves(pair<int, int> position) {
    vector<pair<int, int>> moves;
    int x = position.first;
    int y = position.second;

    // горизонталь (строка)
    for (int i = 0; i < 8; ++i) {
        if (i != x) {
            moves.push_back({i, y}); 
        }
    }

    // вертикаль (столбец)
    for (int j = 0; j < 8; ++j) {
        if (j != y) {
            moves.push_back({x, j}); 
        }
    }

    return moves;
}

// ходы для пешки 
vector<pair<int, int>> pawnMoves(pair<int, int> position) {
    vector<pair<int, int>> moves;
    int x = position.first;
    int y = position.second;

    // пешка может двигаться только вперед на одну клетку по вертикали (вдоль столбца)
    if (x < 7) {
        moves.push_back({x + 1, y}); 
    }

    return moves;
}

// ходы для слона
vector<pair<int, int>> bishopMoves(pair<int, int> position) {
    vector<pair<int, int>> moves;
    int x = position.first;
    int y = position.second;

    // диагонали
    for (int i = 0; i < 8; ++i) {
        if (i != x && y + (i - x) >= 0 && y + (i - x) < 8) {
            moves.push_back({i, y + (i - x)});
        }
        if (i != x && y - (i - x) >= 0 && y - (i - x) < 8) {
            moves.push_back({i, y - (i - x)});
        }
    }

    return moves;
}

// ходы для ферзя
vector<pair<int, int>> queenMoves(pair<int, int> position) {
    vector<pair<int, int>> moves;

    // совместим ходы ладьи и слона для ферзя
    vector<pair<int, int>> rookMovesResult = rookMoves(position);
    vector<pair<int, int>> bishopMovesResult = bishopMoves(position);

    moves.insert(moves.end(), rookMovesResult.begin(), rookMovesResult.end());
    moves.insert(moves.end(), bishopMovesResult.begin(), bishopMovesResult.end());

    return moves;
}

// ходы для короля 
vector<pair<int, int>> kingMoves(pair<int, int> position) {
    vector<pair<int, int>> moves;
    int x = position.first;
    int y = position.second;


    moves.push_back({x - 1, y});
    moves.push_back({x + 1, y});
    moves.push_back({x, y - 1});
    moves.push_back({x, y + 1});
    moves.push_back({x - 1, y - 1});
    moves.push_back({x - 1, y + 1});
    moves.push_back({x + 1, y - 1});
    moves.push_back({x + 1, y + 1});

    return moves;
}

// ходы для коня 
vector<pair<int, int>> knightMoves(pair<int, int> position) {
    vector<pair<int, int>> moves;
    int x = position.first;
    int y = position.second;

 
    moves.push_back({x - 2, y - 1});
    moves.push_back({x - 2, y + 1});
    moves.push_back({x + 2, y - 1});
    moves.push_back({x + 2, y + 1});
    moves.push_back({x - 1, y - 2});
    moves.push_back({x - 1, y + 2});
    moves.push_back({x + 1, y - 2});
    moves.push_back({x + 1, y + 2});

    return moves;
}

void printMoves(const vector<pair<int, int>>& moves) {
    // создала и вывела матрицу 8x8, где каждая клетка показывает наличие хода (1) или отсутствие хода (0)
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            bool hasMove = false;
            // Проверяем, есть ли текущая клетка в списке доступных ходов
            for (const auto& move : moves) {
                if (move.first == i && move.second == j) {
                    hasMove = true;
                    break;
                }
            }
            // вывела 1, если есть ход, и 0 в противном случае
            cout << (hasMove ? "1" : "0") << " ";
        }
        cout << endl;
    }
}

int main() {
  

    // ладья
    pair<int, int> rookPosition = {0, 0};
    vector<pair<int, int>> rookPossibleMoves = rookMoves(rookPosition);

    cout << "ходы для ладьи:" << endl;
    printMoves(rookPossibleMoves);

    // пешка
    pair<int, int> pawnPosition = {1, 1};
    vector<pair<int, int>> pawnPossibleMoves = pawnMoves(pawnPosition);

    cout << "ходы для пешки:" << endl;
    printMoves(pawnPossibleMoves);

    // слон
    pair<int, int> bishopPosition = {2, 2};
    vector<pair<int, int>> bishopPossibleMoves = bishopMoves(bishopPosition);

    cout << "ходы для слона:" << endl;
    printMoves(bishopPossibleMoves);

    // ферзь
    pair<int, int> queenPosition = {3, 3};
    vector<pair<int, int>> queenPossibleMoves = queenMoves(queenPosition);

    cout << "ходы для ферзя:" << endl;
    printMoves(queenPossibleMoves);

    // король
    pair<int, int> kingPosition = {4, 4};
    vector<pair<int, int>> kingPossibleMoves = kingMoves(kingPosition);

    cout << "ходы для короля:" << endl;
    printMoves(kingPossibleMoves);

    //конь
    pair<int, int> knightPosition = {5, 5};
    vector<pair<int, int>> knightPossibleMoves = knightMoves(knightPosition);

    cout << "ходы для коня:" << endl;
    printMoves(knightPossibleMoves);

    return 0;
}
