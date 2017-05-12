#ifndef EASY_H
#define EASY_H

/*! \file easy.h
*   \brief holds the Easy class, derived from Computer class
*
*   AI that is not realy hard to beat, but still tries.
*/

#include "computer.h"
#include <string>

namespace boardgame {

/*! \class Easy
*   \brief Easy is a class used for computer players, derived from the Computer class
*
*   play the best available move using a one-ply look-a-head and piece-count evaluation
*/
class Easy : public Computer {
public:
    /*! \brief Easy constructor
    *   
    *   @param name Name of the player
    */
    explicit Easy(std::string name);
    /*! 'brief Computer destructor
    */
    virtual ~Easy();
    /*! \brief Play Turn.
    *   used when the computer plays a turn.
    */
    virtual void playTurn(Board* board);
};

}

#endif