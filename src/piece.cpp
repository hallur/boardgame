#include "piece.h"
#include <iostream>

Piece::Piece(const char& marker, std::string* player) : marker_(marker), player_(player) {
    //moves_.push_back(std::make_pair(0, -1));
}

Piece::~Piece() {}

std::ostream& operator<<(std::ostream& os, const Piece& rhs) {
    os << rhs.marker_;
    return os;
}