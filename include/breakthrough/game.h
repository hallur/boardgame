#ifndef BREAKTHROUGH_GAME_H
#define BREAKTHROUGH_GAME_H

/*! \file game.h
*   \brief file wich holds the game class for breakthrough game.
*
*   The game inherits from our base boardgame::Game class.
*/

#include "../game.h"

namespace boardgame {
namespace breakthrough {

/*! \class Game
*   \brief Game for breakthrough game, inherits boardgame::Game.
*
*   Holds the game logic for the breakthrough game.
*/
class Game : public boardgame::Game {
public:
    /*! \brief Game constructor
    *
    *   @param player1  Player one.
    *   @oaram player2  Player twho.
    *   @param width    the width of the board, default 8.
    *   @param height   the height of the board, default 8.
    */
    explicit Game(boardgame::Player* player1, boardgame::Player* player2, int width = 8, int height = 8);
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