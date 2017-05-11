#ifndef RANDOM_H
#define RANDOM_H

/*! \file random.h
*   \brief holds the random class, derived from Computer class
*
*   AI that does not really know what it is doing so it just does something.
*/

#include "player.h"
#include <string>

namespace boardgame {

/*! \class Random
*   \brief Random is a class used for computer players, derived from the Computer class
*
*   Not really smart when making decissions  
*/
class Random : public Computer {
public:
    /*! \brief Computer constructor
    *   
    *   @param name Name of the player
    */
    explicit Random(std::string name);
    /*! 'brief Computer destructor
    */
    virtual ~Random();
    /*! \brief Play Turn.
    *   used when the computer plays a turn.
    */
    virtual Move playTurn();
};

}

#endif