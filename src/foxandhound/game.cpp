#include "foxandhound/game.h"
#include "foxandhound/board.h"

boardgame::foxandhound::Game::Game(boardgame::Player* player1, boardgame::Player* player2) : boardgame::Game(player1, player2) {
    board_ = new boardgame::foxandhound::Board(player1, player2);
}

boardgame::foxandhound::Game::~Game() {
    // todo: implement this destructor
    //delete board_;
}

boardgame::Player* boardgame::foxandhound::Game::getWinner() const {
    // todo: implement this function
    return nullptr;
}