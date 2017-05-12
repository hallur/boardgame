#include "game.h"
#include "exceptions.h"

boardgame::Game::Game(boardgame::Player* player1, boardgame::Player* player2, int maxNumberOfMoves) : player1_(player1), player2_(player2), maxNumberOfMoves_(maxNumberOfMoves) {
    currentPlayer_ = player1_;
}

boardgame::Game::~Game() {}

void boardgame::Game::playTurn() {
    currentPlayer_->playTurn(board_);
}

void boardgame::Game::display() const {
    std::cout << *board_ << std::endl;
    std::cout << (currentPlayer_ == player1_ ? 0 : 1) << std::endl;
    std::cout << board_->countPiecesFor(player1_) << ' ' << board_->countPiecesFor(player2_) << std::endl;
}

void boardgame::Game::switchCurrentPlayer() {
    currentPlayer_ = (currentPlayer_ == player1_ ? player2_ : player1_);
}

void boardgame::Game::retract() {
    board_->retract();
}