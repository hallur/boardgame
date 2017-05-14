#ifndef PLAYER_H
#define PLAYER_H

/*! \file player.h
*   \brief Contains base class for players in boardgames.
*/

#include <string>

namespace boardgame {

class Board; // forward decleration

/*! \class Player
*   \brief base class for players in games, pure virtual.
*
*   Class player holds the player name and defines basic functions for every player and functions that must
*   be defined in derived classes such as computer and human.
*/  
class Player {
public:
    /*! \brief Player constructor
    *   Sets the name of player.
    *   @param name String to identify player
    */
    explicit Player(std::string name);
    /*! \brief ~Player destructor
    */
    virtual ~Player();

    /*! \fn playTurn
    *   \brief Player playTurn()
    *
    *   Pure virtual, to be overwritten in derived classes such as player and computer.
    *
    *   @param board    an instance of the board so the computer can calculate a move.
    */
    virtual void playTurn(Board* board) = 0;
protected:
    std::string name_; //!< Name used to identify player for the user 
};

}

#endif