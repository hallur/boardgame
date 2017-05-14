#ifndef RANDOM_H
#define RANDOM_H

/*! \file random.h
*   \brief holds the random class, derived from Computer class
*
*   AI that does not really know what it is doing so it just does something.
*/

#include "computer.h"
#include <string>

namespace boardgame {

/*! \class Random
*   \brief Random is a class used for computer players, derived from the Computer class
*
*   Not really smart when making decissions  
*/
class Random : public Computer {
public:
    /*! \brief Random constructor
    *   
    *   @param name Name of the player
    */
    explicit Random(std::string name);
    /*! \brief ~Random destructor
    */
    virtual ~Random();

    /*! \fn playTurn
    *   \brief Play Turn.
    *
    *   used when the computer plays a turn.
    *
    *   @param board    an instance of the board so the computer can calculate a move.
    */
    virtual void playTurn(Board* board);
};

}

#endif