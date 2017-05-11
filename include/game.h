#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

#include <string>
#include <iostream>

namespace boardgame {

class Game {
public:
    explicit Game(Player* player1, Player* player2, int maxNumberOfMoves = -1);
    virtual ~Game();

    virtual Player* getWinner() const = 0;
    void display() const;
    void playTurn();

protected:
    Player* player1_;
    Player* player2_;
    const int maxNumberOfMoves_;
    Board* board_;
    Player* currentPlayer_;
};

}

#endif