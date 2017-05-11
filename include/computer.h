#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include <string>

namespace boardgame {

/*! \enum Difficulty
*   used for choosing difficulty of computer AI
*/
enum class Difficulty { random, easy, medium, hard };

/*! \class Computer
*   \breif Computer is a class used for computer players, derived from the Player class
*
*   Uses AI to interact with the came, can have different difficultys.   
*/
class Computer : public Player {
public:
    /*! \breif Computer constructor
    *   
    *   @param name Name of the player
    */
    explicit Computer(std::string name, Difficulty difficulty);
    /*! 'breif Computer destructor
    */
    virtual ~Computer();
    /*! \breif Play Turn.
    *   used when the computer plays a turn.
    */
    virtual Move playTurn();
private:
    Difficulty difficulty_; //!< holds the difficulty of the AI
};

}

#endif