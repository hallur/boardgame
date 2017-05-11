#include "foxandhound/game.h"
#include "foxandhound/board.h"

boardgame::foxandhound::Game::Game(boardgame::Player* player1, boardgame::Player* player2) : boardgame::Game(player1, player2) {
    board_ = new boardgame::foxandhound::Board(player1, player2);
}

boardgame::foxandhound::Game::~Game() {
    delete board_;
}

boardgame::Player* boardgame::foxandhound::Game::getWinner() const {
    // todo: thought; is casting the right approach here?
    auto board = dynamic_cast<foxandhound::Board*>(board_);
    auto foxLocation = board->getFoxLocation();
    auto houndLocations = board->getHoundLocations();
    // check if player 1 (fox) is winner
    bool foxIsWinner = true;
    for (int i = 0; i < 4; i++) {
        auto currentHoundLocation = houndLocations[i];
        if (currentHoundLocation.y < foxLocation.y) {
            foxIsWinner = false;
            break;
        }
    }
    if (foxIsWinner) {
        return player1_;
    }
    // check if player 2 (hounds) is winner
    if (board->getLegalMovesFor(foxLocation).empty()) {
        return player2_;
    }
    return nullptr;
}