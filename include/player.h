#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace boardgame {

/*! \class Player
*   \breif base class for players in games, pure virtual.
*
*   Class player holds the player name and defines basic functions for every player and functions that must
*   be defined in derived classes such as computer and human.
*/  
class Player {
public:
    /*! \breif Player constructor
    *   Sets the name of player.
    *   @param name String to identify player
    */
    explicit Player(std::string name) : name_(name) {};
    /*! \breif Player destructor
    */
    virtual ~Player() {};
    /*! \breif Player playTurn()
    *   Pure virtual, to be overwritten in derived classes such as player and computer.
    */
    virtual void playTurn() = 0;
protected:
    std::string name_; //!< Name used to identify player for the user 
};

}

#endif