#include "foxandhound/board.h"
#include "foxandhound/fox.h"
#include "foxandhound/hound.h"

boardgame::foxandhound::Board::Board(boardgame::Player* player1, boardgame::Player* player2) : boardgame::Board(8, 8) {
    initialize(player1, player2);
}

boardgame::foxandhound::Board::~Board() {}

void boardgame::foxandhound::Board::initialize(boardgame::Player* player1, boardgame::Player* player2) {
    // delete pre-existing pieces
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (pieces_[y][x]) {
                delete pieces_[y][x];
            }
        }
    }
    // place new pieces in initial positions
    for (int x = 0; x < width_; x++) { // row 1
        pieces_[0][x] = (x % 2 != 0) ? new boardgame::foxandhound::Hound(player2) : nullptr;
    }
    for (int y = 1; y < height_ - 1; y++) { // row 2-7
        for (int x = 0; x < width_; x++) {
            pieces_[y][x] = nullptr;
        }
    }
    for (int x = 0; x < width_; x++) { // row 8
        pieces_[7][x] = (x != 0 && x % 4 == 0) ? new boardgame::foxandhound::Fox(player1) : nullptr;
    }
}