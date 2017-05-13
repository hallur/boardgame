#include "megabreakthrough/board.h"
#include "megabreakthrough/pawn.h"
#include "megabreakthrough/megapawn.h"
#include "exceptions.h"

boardgame::megabreakthrough::Board::Board(boardgame::Player* player1, boardgame::Player* player2, int width, int height) : boardgame::Board(width, height) {
    if (height < 4 || width < 1) {
        throw illegal_board_dimentions_exception();
    }
    initialize(player1, player2);
}

boardgame::megabreakthrough::Board::Board(const boardgame::megabreakthrough::Board& rhs) : boardgame::Board::Board(rhs) {}

boardgame::megabreakthrough::Board::~Board() {}

void boardgame::megabreakthrough::Board::initialize(boardgame::Player* player1, boardgame::Player* player2) {
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
        pieces_[0][x] = new boardgame::megabreakthrough::MegaPawn(player2, true);
        pieces_[1][x] = new boardgame::megabreakthrough::Pawn(player2, true);
    }
    for (int y = 2; y < height_ - 2; y++) { // row 3 to (bottom - 2)
        for (int x = 0; x < width_; x++) {
            pieces_[y][x] = nullptr;
        }
    }
    for (int x = 0; x < width_; x++) { // row bottom and bottom - 1
        pieces_[height_-2][x] = new boardgame::megabreakthrough::Pawn(player1, false);
        pieces_[height_-1][x] = new boardgame::megabreakthrough::MegaPawn(player1, false);
    }
}

boardgame::Player* boardgame::megabreakthrough::Board::playerOnWinningTile(boardgame::Player* player1, boardgame::Player* player2) {
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