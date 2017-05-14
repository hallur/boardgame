#ifndef GAME_H
#define GAME_H

/*! \file /boardgame/include/game.h
*   \brief contains base class Game used for games
*/

#include "structs.h"
#include "board.h"
#include "player.h"

#include <string>
#include <iostream>

namespace boardgame {

/*! \class Game
*   \brief base class for all games, pure virtual
*
*   Class that holds everything a game should need, the players involved, maximum number of moves, the game board, whose turn it is etc.
*/
class Game {
public:
    /*! \brief Game constructor
    *
    *   creates a new instance of a game.
    *
    *   @param player1 player one.
    *   @param player2 player two.
    *   @param maxNumberOfMoves maximum number of moves the game can have (after that if there is no winner the game is a tie.) default -1 (infinite number of moves).
    */
    explicit Game(Player* player1, Player* player2, int maxNumberOfMoves = -1);
    /*! \brief ~Game destructor
    */
    virtual ~Game();

    /*! \fn playTurn
    *   \brief plays next turn
    *   
    *   makes the player who is suposed to make a move play.
    */
    void playTurn();
    /*! \fn virtual Player * boardgame::Game::getWinner() const =0
    *   \brief gets winner
    *
    *   checks if there is a winner, if there is one return the winner if ther in no winner yet returns nullPtr.
    */
    virtual Player* getWinner() const = 0;
    /*! \fn display
    *   \brief Print board
    *
    *   Prints the board in the current state.
    */
    void display() const;
    /*! \fn switchCurrentPlayer
    *   \brief changes currentPlayer
    */
    void switchCurrentPlayer();
    /*! \fn retract
    *   \brief retracts one move backwards.
    */
    void retract();

protected:
    Player* player1_; //!< Player one
    Player* player2_; //!< Player two
    const int maxNumberOfMoves_; //!< Maximum number of moves (before tie?), -1 if there is no maximum number of moves
    Board* board_; //!< The game board
    Player* currentPlayer_; //!< Current player / whose turn it is
};

}

#endif