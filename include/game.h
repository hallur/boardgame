#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <string>
#include <iostream>

namespace boardgame {

class Game {
public:
    explicit Game();
    virtual ~Game();

    virtual void initialize();
    virtual void playTurn();
    virtual std::string* getWinner() const;
    virtual void printBoard() const;

protected:
    Piece* getPieceFromUser(const std::string& message) const;

    Board board_;
    std::string player1_;
    std::string player2_;
    std::string* currentPlayer_;
};

}

#endif