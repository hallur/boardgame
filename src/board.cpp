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

boardgame::Piece* boardgame::Board::getPieceAt(Location location) const {
    if ((location.x < 0 || location.x >= width_) || (location.y < 0 || location.y >= height_)) {
        throw std::out_of_range("argument 'location' out of bounds");
    }
    return pieces_[location.y][location.x];
}

bool boardgame::Board::movePiece(Location from, Location to) {
    Piece* fromPiece = getPieceAt(from);
    if (!fromPiece)
        return false;
    Piece* toPiece = getPieceAt(to);
    if (toPiece)
        delete toPiece;
    toPiece = fromPiece;
    fromPiece = nullptr;
    return true;
}

std::vector<boardgame::Location> boardgame::Board::getLegalMovesFor(boardgame::Location location) const {
    return std::vector<Location>();
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