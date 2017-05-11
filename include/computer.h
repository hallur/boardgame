#ifndef COMPUTER_H
#define COMPUTER_H

/*! \file computer.h
*   \brief holds the computer class, derived from Player class
*
*   AI that can challange Human or other Computer, derived from Player
*   will be base class of multiple difficulties
*/

#include "player.h"
#include <string>

namespace boardgame {

/*! \class Computer
*   \brief Computer is a class used for computer players, derived from the Player class
*
*   Uses AI to interact with the came, can have different difficultys.   
*/
class Computer : public Player {
public:
    /*! \brief Computer constructor
    *   
    *   @param name Name of the player
    */
    explicit Computer(std::string name);
    /*! 'brief Computer destructor
    */
    virtual ~Computer();
    /*! \brief Play Turn.
    *   used when the computer plays a turn.
    */
    virtual Move playTurn();
};

}

#endif