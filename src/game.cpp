#include "game.h"

boardgame::Game::Game(boardgame::Player* player1, boardgame::Player* player2, int maxNumberOfMoves, boardgame::Board board) : player1_(player1), player2_(player2), maxNumberOfMoves_(maxNumberOfMoves), board_(board) {
    currentPlayer_ = player1_;
}

boardgame::Game::~Game() {}

/*void boardgame::Game::initialize() {
    currentPlayer_ = &player1_;
    board_ = Board(3, 3);
}*/

void boardgame::Game::playTurn() {

}

boardgame::Player* boardgame::Game::getWinner() const {
    return nullptr;
}

void boardgame::Game::printBoard() const {
    std::cout << board_;
}

/*boardgame::Piece* boardgame::Game::getPieceFromUser(const std::string& message) const {
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
}*/