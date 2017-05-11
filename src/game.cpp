#include "game.h"

boardgame::Game::Game(boardgame::Player* player1, boardgame::Player* player2, int maxNumberOfMoves) : player1_(player1), player2_(player2), maxNumberOfMoves_(maxNumberOfMoves) {
    currentPlayer_ = player1_;
}

boardgame::Game::~Game() {}

void boardgame::Game::playTurn() {
    // todo: implement this function
}

void boardgame::Game::display() const {
    std::cout << *board_ << std::endl;
    std::cout << (currentPlayer_ == player1_ ? 0 : 1) << std::endl;
    // todo: print number of pieces for both players
}