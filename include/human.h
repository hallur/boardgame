#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include <string>

namespace boardgame {

/*! \class Human
*   \breif Human is a class used for human players, derived from the Player class
*
*   The class defines playTurn so that a human can interact in the game.
*/
class Human : public Player {
public:
    /*! \breif Human constructor
    *   
    *   @param name Name of the player
    */
    explicit Human(std::string name);
    /*! \breif Human destructor
    */
    virtual ~Human();
    /*! \breif Play Turn.
    *   used when playing a turn.
    */
    virtual void playTurn();
};

}

#endif