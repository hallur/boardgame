#ifndef FOXANDHOUND_GAME_H
#define FOXANDHOUND_GAME_H

/*! \file game.h
*   \brief file wich holds the game class for fox and hounds game.
*
*   The game inherits from our base boardgame::Game class.
*/

#include "../game.h"

namespace boardgame {
namespace foxandhound {

/*! \class Game
*   \brief Game for fox and hounds game, inherits boardgame::Game.
*
*   Holds the game logic for the fox and hounds game.
*/
class Game : public boardgame::Game {
public:
    /*! \brief Game constructor
    *
    *   @param player1  Player one.
    *   @oaram player2  Player two.
    */
    explicit Game(boardgame::Player* player1, boardgame::Player* player2);
    /*! \breif ~Game destructor
    */
    virtual ~Game();
    
    /*! \fn getWinner
    *   \breif returns the winner of the game, (nullptr gets returned if there is no winner yet).
    */
    virtual boardgame::Player* getWinner() const;
};

}}

#endif