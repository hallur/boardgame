#include "breakthrough/board.h"
#include "breakthrough/pawn.h"
#include "exceptions.h"

boardgame::breakthrough::Board::Board(boardgame::Player* player1, boardgame::Player* player2, int width, int height) : boardgame::Board(width, height) {
    if (height < 4 || width < 1) {
        throw illegal_board_dimentions_exception();
    }
    initialize(player1, player2);
}

boardgame::breakthrough::Board::Board(const boardgame::breakthrough::Board& rhs) : boardgame::Board::Board(rhs) {}

boardgame::breakthrough::Board::~Board() {}

void boardgame::breakthrough::Board::initialize(boardgame::Player* player1, boardgame::Player* player2) {
    // delete pre-existing pieces
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (pieces_[y][x]) {
                delete pieces_[y][x];
            }
        }
    }
    // place new pieces in initial positions
    for (int x = 0; x < width_; x++) { // row 1 and 2
        pieces_[0][x] = new boardgame::breakthrough::Pawn(player2, true);
        pieces_[1][x] = new boardgame::breakthrough::Pawn(player2, true);
    }
    for (int y = 2; y < height_ - 2; y++) { // row 3 to (bottom - 2)
        for (int x = 0; x < width_; x++) {
            pieces_[y][x] = nullptr;
        }
    }
    for (int x = 0; x < width_; x++) { // row bottom and bottom - 1
        pieces_[height_-2][x] = new boardgame::breakthrough::Pawn(player1, false);
        pieces_[height_-1][x] = new boardgame::breakthrough::Pawn(player1, false);
    }
}

boardgame::Player* boardgame::breakthrough::Board::playerOnWinningTile(boardgame::Player* player1, boardgame::Player* player2) {
    for (int x = 0; x < width_; x++) { // row 1 and 2
        if ( pieces_[0][x] ) {
            if ( pieces_[0][x]->getPlayer() == player1) {
                return player1;
            }
        }
        if ( pieces_[height_-1][x] ) {
            if (pieces_[height_-1][x]->getPlayer() == player2) {
                return player2;
            }
        }
    }
    return nullptr;
}