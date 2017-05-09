#include "game.h"

Game::Game() : player1_("Player 1"), player2_("Player 2") {
    initialize();
}

Game::~Game() {}

void Game::initialize() {
    currentPlayer_ = &player1_;
    board_ = Board();
}

void Game::playTurn() {
    /*Piece* from = getPieceFromUser("From [x, y]: ");
    Piece* to = getPieceFromUser("To [x, y]: ");*/
}

std::string* Game::getWinner() const {
    return nullptr;
}

void Game::printBoard() const {
    std::cout << board_;
}

Piece* Game::getPieceFromUser(const std::string& message) const {
    while (true) {
        int x, y;
        std::cout << message;
        std::cin >> x >> y;

        try {
            return board_.getPiece(x, y);
        } catch (int e) {
            std::cout << "Selection out of bounds. Try again.";
        }
    }
}