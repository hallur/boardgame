#include "game.h"
#include "exceptions.h"

boardgame::Game::Game(boardgame::Player* player1, boardgame::Player* player2, int maxNumberOfMoves) : player1_(player1), player2_(player2), maxNumberOfMoves_(maxNumberOfMoves) {
    currentPlayer_ = player1_;
}

boardgame::Game::~Game() {}

boardgame::Player* boardgame::Game::getPlayer1() const {
    return player1_;
}

boardgame::Player* boardgame::Game::getPlayer2() const {
    return player2_;
}

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
    if (board_->retract()) {
        switchCurrentPlayer();
    }
}

void boardgame::Game::initialize(Player* player1, Player* player2) {
    board_->initialize(player1, player2);
}

void boardgame::Game::printLegalMovesForCurrentPlayer() const {
    board_->printLegalMovesFor(currentPlayer_);
}

boardgame::Board* boardgame::Game::getBoard() const {
    return board_;
}

boardgame::Player* boardgame::Game::getCurrentPlayer() const {
    return currentPlayer_;
}