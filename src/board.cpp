#include "board.h"
#include "exceptions.h"

#include <typeinfo>
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

void boardgame::Board::movePiece(boardgame::Location from, boardgame::Location to, Player* player) {
    std::vector<boardgame::Location> legalMoves;
    boardgame::Piece* fromPiece = nullptr;
    try {
        fromPiece = getPieceAt(from);
    } catch (std::out_of_range e) {
        throw std::out_of_range("argument 'from' out of bounds");
    }
    if (fromPiece) {
        if (fromPiece->getPlayer() != player) {
            throw boardgame::illegal_move_exception();
        }
    }
    boardgame::Piece* toPiece = nullptr;
    try {
        toPiece = getPieceAt(to);
    } catch(std::out_of_range e) {
        throw std::out_of_range("argument 'to' out of bounds");
    }
    legalMoves = getLegalMovesFor(from); // no need to try-catch this
    if (std::find(legalMoves.begin(), legalMoves.end(), to) == legalMoves.end()) {
        throw boardgame::illegal_move_exception();
    }
    MoveHistoryState state(Move(from, to));
    if (toPiece) {
        graveyard_.push(pieces_[to.y][to.x]);
        state.kill = true;
    }
    moveHistory_.push(state);
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
            int continuousLenght = moveRule.contLength;
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
                continuousLenght--;
            } while (moveRule.continuous && continuousLenght != 0);
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

std::vector<boardgame::Location> boardgame::Board::getPieceLocationsFor(Player* player) const {
    std::vector<boardgame::Location> locations;
    for (int y = 0; y < width_; y++) {
        for (int x = 0; x < height_; x++) {
            if (pieces_[y][x]) {
                if (pieces_[y][x]->getPlayer() == player) {
                    locations.push_back(Location(x,y));
                }
            }
        }
    }
    return locations;
}

bool boardgame::Board::retract() {
    if (!moveHistory_.empty()) {
        MoveHistoryState state = moveHistory_.top();
        moveHistory_.pop();
        pieces_[state.move.from.y][state.move.from.x] = pieces_[state.move.to.y][state.move.to.x];
        if (state.kill) {
            Piece* piece = graveyard_.top();
            graveyard_.pop();
            pieces_[state.move.to.y][state.move.to.x] = piece;
        } else {
            pieces_[state.move.to.y][state.move.to.x] = nullptr;
        }
        return true;
    }
    return false;
}

void boardgame::Board::printLegalMovesFor(Player* player) const {
    for (auto piece : getPieceLocationsFor(player)) {
        for (auto move : getLegalMovesFor(piece)) {
            std::cout << (char)(piece.x + 'a')
                      << getHeight() - piece.y
                      << " "
                      << (char)(move.x + 'a')
                      << getHeight() - move.y
                      << std::endl;
        }
    }
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