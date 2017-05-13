#include "megabreakthrough/game.h"
#include "megabreakthrough/board.h"
#include "exceptions.h"

#include <iostream>

boardgame::megabreakthrough::Game::Game(boardgame::Player* player1, boardgame::Player* player2, int width, int height) : boardgame::Game(player1, player2) {
    try {
        board_ = new boardgame::megabreakthrough::Board(player1, player2, width, height);
    } catch (illegal_board_dimentions_exception& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        throw;
    }
}

boardgame::megabreakthrough::Game::~Game() {
    delete board_;
}

boardgame::Player* boardgame::megabreakthrough::Game::getWinner() const {
    auto board = dynamic_cast<megabreakthrough::Board*>(board_);
    if ( board->playerOnWinningTile(player1_, player2_) == player1_) {
        return player1_;
    }
    else if ( board->playerOnWinningTile(player1_, player2_) == player2_) {
        return player2_;
    }
    return nullptr;
}