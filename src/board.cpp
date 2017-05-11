#include "board.h"
#include "exceptions.h"

#include <algorithm>
#include <iostream>
#include <string>

boardgame::Board::Board(const int& width, const int &height) : width_(width), height_(height) {
    pieces_ = new Piece**[height];
    for (int y = 0; y < height; y++) {
        pieces_[y] = new Piece*[width];
        for (int x = 0; x < width_; x++) {
            pieces_[y][x] = nullptr;
        }
    }
}

boardgame::Board::Board(const Board& rhs) : width_(rhs.width_), height_(rhs.height_) {
    pieces_ = new Piece**[rhs.height_];
    for (int y = 0; y < rhs.height_; y++) {
        pieces_[y] = new Piece*[rhs.width_];
        for (int x = 0; x < rhs.width_; x++) {
            pieces_[y][x] = rhs.pieces_[y][x]; // todo: should work without overloaded assignment operator but needs to be tested
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

int boardgame::Board::getHeight() const {
    return height_;
}

boardgame::Piece* boardgame::Board::getPieceAt(boardgame::Location location) const {
    if ((location.x < 0 || location.x >= width_) || (location.y < 0 || location.y >= height_)) {
        throw std::out_of_range("argument 'location' out of bounds");
    }
    return pieces_[location.y][location.x];
}

void boardgame::Board::movePiece(boardgame::Location from, boardgame::Location to) {
    std::vector<boardgame::Location> legalMoves;
    try {
        legalMoves = getLegalMovesFor(from);
    } catch (std::out_of_range e) {
        throw std::out_of_range("argument 'from' out of bounds");
    }
    if (std::find(legalMoves.begin(), legalMoves.end(), to) == legalMoves.end()) {
        throw boardgame::illegal_move_exception();
    }
    boardgame::Piece* toPiece = nullptr;
    try {
        toPiece = getPieceAt(to);
    } catch(std::out_of_range e) {
        throw std::out_of_range("argument 'from' out of bounds");
    }
    if (toPiece) {
        delete toPiece;
    }
    pieces_[to.y][to.x] = pieces_[from.y][from.x];
    pieces_[from.y][from.x] = nullptr; // Hlynur approves
}

std::vector<boardgame::Location> boardgame::Board::getLegalMovesFor(boardgame::Location location) const {
    std::vector<boardgame::Location> legalMoves;
    boardgame::Piece* piece = nullptr;
    try {
        piece = getPieceAt(location);
    } catch (std::out_of_range e) {
        throw e;
    }
    if (piece) {
        std::vector<boardgame::MoveRule> moveRules = piece->getMoveRules();
        for (auto moveRule : moveRules) {
            boardgame::Location tmpLocation = location;
            do {
                tmpLocation.x += moveRule.xDiff;
                tmpLocation.y += moveRule.yDiff;
                boardgame::Piece* targetPiece = nullptr;
                try {
                    targetPiece = getPieceAt(tmpLocation);
                } catch (std::out_of_range e) {
                    break;
                }
                if (!targetPiece) {
                    legalMoves.push_back(tmpLocation);
                } else {
                    if (moveRule.kill && targetPiece->getPlayer() != piece->getPlayer()) {
                        legalMoves.push_back(tmpLocation);
                    }
                    break;
                }
            } while (moveRule.continuous);
        }   
    }
    return legalMoves;
}

int boardgame::Board::countPiecesFor(Player* player) const {
    int pieceCount = 0;
    for (int y = 0; y < width_; y++) {
        for (int x = 0; x < height_; x++) {
            if (pieces_[y][x]) {
                if (pieces_[y][x]->getPlayer() == player) {
                    pieceCount++;
                }
            }
        }
    }
    return pieceCount;
}

std::ostream& boardgame::operator<<(std::ostream& os, const boardgame::Board& rhs) {
    for (int y = 0; y < rhs.height_; y++) {
        os << (rhs.height_ - y) << ' ';
        for (int x = 0; x < rhs.width_; x++) {
            if (rhs.pieces_[y][x]) {
                os << *rhs.pieces_[y][x];
            } else {
                os << '.';
            }
        }
        os << std::endl;
    }
    os << "  ";
    for (int x = 0; x < rhs.width_; x++) {
        os << static_cast<char>(x + 97);
    }
    return os;
}