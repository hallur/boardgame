#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <string>
#include <iostream>

namespace boardgame {

class Game {
public:
    explicit Game(Player* player1, Player* player2, Board board);
    explicit Game(Player* player1, Player* player2);
    virtual ~Game();

    //virtual void initialize();
    virtual void playTurn();
    virtual Player* getWinner() const;
    virtual void printBoard() const;

protected:
    //Piece* getPieceFromUser(const std::string& message) const;

    Board board_;
    Player* player1_;
    Player* player2_;
    Player* currentPlayer_;
};

}

#endif