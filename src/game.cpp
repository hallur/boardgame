#include "game.h"
#include "exceptions.h"

boardgame::Game::Game(boardgame::Player* player1, boardgame::Player* player2, int maxNumberOfMoves) : player1_(player1), player2_(player2), maxNumberOfMoves_(maxNumberOfMoves) {
    currentPlayer_ = player1_;
}

boardgame::Game::~Game() {}

void boardgame::Game::playTurn() {
    bool invalidInput = true;
    while(invalidInput){
        try {
            Move turn = currentPlayer_->playTurn();
            turn.from.y = board_->getHeight() - turn.from.y;
            turn.to.y = board_->getHeight() - turn.to.y;
            board_->movePiece(turn.from, turn.to);
            invalidInput = false;
        } catch (std::out_of_range& e) {
            std::cout << "Out of Range error: " << e.what() << std::endl;
        } catch(boardgame::illegal_move_exception& e) {
            std::cout << e.what() << std::endl;
        }catch (...) {
            std::cerr << "An unknown error has accured! When moving." << std::endl;
            throw;
        }
    }
}

void boardgame::Game::display() const {
    std::cout << *board_ << std::endl;
    std::cout << (currentPlayer_ == player1_ ? 0 : 1) << std::endl;
    std::cout << board_->countPiecesFor(player1_) << ' ' << board_->countPiecesFor(player2_) << std::endl;
}

void boardgame::Game::switchCurrentPlayer() {
    currentPlayer_ = (currentPlayer_ == player1_ ? player2_ : player1_);
}