#include "piece.h"
#include <iostream>

boardgame::Piece::Piece(const char& marker, boardgame::Player* player) : marker_(marker), player_(player) {}

boardgame::Piece::~Piece() {}

std::ostream& boardgame::operator<<(std::ostream& os, const boardgame::Piece& rhs) {
    os << rhs.marker_;
    return os;
}