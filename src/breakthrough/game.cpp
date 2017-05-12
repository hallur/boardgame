#include "breakthrough/game.h"
#include "breakthrough/board.h"
#include "exceptions.h"

#include <iostream>

boardgame::breakthrough::Game::Game(boardgame::Player* player1, boardgame::Player* player2, int width, int height) : boardgame::Game(player1, player2) {
    try {
        board_ = new boardgame::breakthrough::Board(player1, player2, width, height);
    } catch (illegal_board_dimentions_exception& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        throw;
    }
}

boardgame::breakthrough::Game::~Game() {
    delete board_;
}

boardgame::Player* boardgame::breakthrough::Game::getWinner() const {
    auto board = dynamic_cast<breakthrough::Board*>(board_);
    if ( board->playerOnWinningTile(player1_, player2_) == player1_) {
        return player1_;
    }
    else if ( board->playerOnWinningTile(player1_, player2_) == player2_) {
        return player2_;
    }
    return nullptr;
}