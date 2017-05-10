#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <string>
#include <iostream>

namespace boardgame {

class Game {
public:
    explicit Game(Player* player1, Player* player2, int maxNumberOfMoves, Board board = Board());
    virtual ~Game();

    //virtual void initialize();
    virtual void playTurn();
    virtual Player* getWinner() const;
    virtual void printBoard() const;

protected:
    //Piece* getPieceFromUser(const std::string& message) const;
    Player* player1_;
    Player* player2_;
    const int maxNumberOfMoves_;
    Board board_;
    Player* currentPlayer_;
};

}

#endif