#include "piece.h"
#include <iostream>

boardgame::Piece::Piece(const char& marker, boardgame::Player* player) : marker_(marker), player_(player) {
    moves_ = {
        {0, -1}, // up
        {1, 0},  // right
        {0, 1},  // down
        {-1, 0}  // left
    };

    killMoves_ = {
        {1, -1}, // up-right
        {1, 1},  // down-right
        {-1, 1}, // down-left
        {-1, -1} // up-left
    };
}

boardgame::Piece::~Piece() {}

std::ostream& boardgame::operator<<(std::ostream& os, const boardgame::Piece& rhs) {
    os << rhs.marker_;
    return os;
}