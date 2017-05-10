#include "board.h"
#include <string>
#include <iostream>

boardgame::Board::Board() : Board(4, 4) {}

boardgame::Board::Board(const int& width, const int &height) : width_(width), height_(height) {
    pieces_ = new Piece**[height];
    for (int y = 0; y < height; y++) {
        pieces_[y] = new Piece*[width];
        for (int x = 0; x < width; x++) {
            pieces_[y][x] = nullptr;
        }
    }
}

boardgame::Board::~Board() {
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (pieces_[y][x]) {
                delete pieces_[y][x];
            }
        }
    }
}

boardgame::Piece* boardgame::Board::getPiece(const int& x, const int& y) const {
    if ((x < 0 || x >= width_) || (y < 0 || y >= height_)) {
        throw std::out_of_range("x and/or y out of range");
    }
    return pieces_[y][x];
}

bool boardgame::Board::move(Piece* from, Piece* to) {
    if (!from)
        return false;
    if (to)
        delete to;
    to = from;
    from = nullptr;
    return true;
}

std::vector<boardgame::Piece*> boardgame::Board::getLegalMoves(Piece* piece) const {
    return std::vector<Piece*>();
}

std::ostream& boardgame::operator<<(std::ostream& os, const boardgame::Board& rhs) {
    for (int y = 0; y < rhs.height_; y++) {
        for (int x = 0; x < rhs.width_; x++) {
            if (rhs.pieces_[y][x]) {
                os << *rhs.pieces_[y][x];
            } else {
                os << '#';
            }
            os << ' ';
        }
        os << std::endl;
    }
    return os;
}