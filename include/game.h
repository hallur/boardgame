#ifndef GAME_H
#define GAME_H

/*! \file game.h
*   \breif contains base class for games
*/

#include "structs.h"
#include "board.h"
#include "player.h"

#include <string>
#include <iostream>

namespace boardgame {

/*! \class Game
*   \breif base class for all games, pure virtual
*
*   Class that holds everything a game should need, the players involved, maximum number of moves, the game board, whose turn it is etc.
*/
class Game {
public:
    // TODO
    explicit Game(Player* player1, Player* player2, int maxNumberOfMoves = -1);
    /*! \breif game destructor
    */
    virtual ~Game();
    /*! \breif Play turn
    *
    *   ...
    */
    void playTurn();
    /*! \breif Get winner
    *
    *   checks if there is a winner, if there is one return the winner if ther in no winner yet returns nullPtr;
    /   if there is a tie TODO!
    */
    virtual Player* getWinner() const = 0;
    /*! \breif Pring board
    *
    *   Prints the board in the current state.
    */
    void display() const;
    void switchCurrentPlayer(); // document this function

protected:
    Player* player1_; //!< Player one
    Player* player2_; //!< Player two
    const int maxNumberOfMoves_; //!< Maximum number of moves (before tie?), -1 if there is no maximum number of moves
    Board* board_; //!< The game board
    Player* currentPlayer_; //!< Current player / whose turn it is
};

}

#endif