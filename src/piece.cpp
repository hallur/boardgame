#include "piece.h"
#include <iostream>

boardgame::Piece::Piece(boardgame::Player* player, const char& marker) : marker_(marker), player_(player) {}

boardgame::Piece::~Piece() {}

char boardgame::Piece::getMarker() const {
    return marker_;
}

boardgame::Player* boardgame::Piece::getPlayer() const {
    return player_;
}

void boardgame::Piece::setPlayer(boardgame::Player* player) {
    player_ = player; 
}

std::vector<boardgame::MoveRule> boardgame::Piece::getMoveRules() const {
    return moveRules_;
}

std::ostream& boardgame::operator<<(std::ostream& os, const boardgame::Piece& rhs) {
    os << rhs.marker_;
    return os;
}