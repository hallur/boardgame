#include "board.h"
#include <string>
#include <iostream>

Board::Board() {
    for (int y = 0; y < 3; y++) {
        std::vector<Piece*> row;
        for (int x = 0; x < 3; x++) {
            row.push_back(nullptr);
        }
        pieces_.push_back(row);
    }
}

Board::~Board() {
    for (int y = 0; y < getHeight(); y++) {
        for (int x = 0; x < getWidth(); x++) {
            if (pieces_.at(y).at(x)) {
                delete pieces_.at(y).at(x);
            }
        }
    }
}

Piece* Board::getPiece(const int& x, const int& y) const {
    if ((x < 0 || x >= getWidth()) || (y < 0 || y >= getHeight())) {
        throw std::out_of_range("x and/or y out of range");
    }
    return pieces_.at(y).at(x);
}

int Board::getWidth() const {
    if (!pieces_.empty())
        return static_cast<int>(pieces_.at(0).size());
    return 0;
}

int Board::getHeight() const {
    return static_cast<int>(pieces_.size());
}

bool Board::move(Piece* from, Piece* to) {
    if (!from)
        return false;
    if (to)
        delete to;
    to = from;
    from = nullptr;
    return true;
}

std::vector<Piece*> Board::getLegalMoves(Piece* piece) const {
    return std::vector<Piece*>();
}

std::ostream& operator<<(std::ostream& os, const Board& rhs) {
    for (int y = 0; y < rhs.getHeight(); y++) {
        for (int x = 0; x < rhs.getWidth(); x++) {
            if (rhs.pieces_.at(y).at(x)) {
                os << *rhs.pieces_.at(y).at(x);
            } else {
                os << '#';
            }
            os << ' ';
        }
        os << std::endl;
    }
    return os;
}