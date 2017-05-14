#ifndef HUMAN_H
#define HUMAN_H

/*! \file human.h
*   \brief Comntains Human player
*
*   Human player derived from the Player class
*/

#include "player.h"

#include <string>

namespace boardgame {

/*! \class Human
*   \brief Human is a class used for human players, derived from the Player class
*
*   The class defines playTurn so that a human can interact in the game.
*/
class Human : public Player {
public:
    /*! \brief Human constructor
    *   
    *   @param name Name of the player
    */
    explicit Human(std::string name);
    /*! \brief Human destructor
    */
    virtual ~Human();

    /*! \fn playTurn
    *   \brief Play Turn.
    *
    *   used when playing a turn.
    *
    *   @param board    an instance of the board so the computer can calculate a move.
    */
    virtual void playTurn(Board* board);
};

}

#endif