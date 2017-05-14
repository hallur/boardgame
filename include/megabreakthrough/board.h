#ifndef MEGABREAKTHROUGH_BOARD_H
#define MEGABREAKTHROUGH_BOARD_H

/*! \file board.h
*   \brief file wich holds the board for mega breakthrough game.
*
*   The board inherits from our base boardgame::Board class, and implements some
*   additional features for the mega breakthrough game.
*/

#include "../breakthrough/board.h"

namespace boardgame {
namespace megabreakthrough {

/*! \class Board
*   \brief Board for mega breakthrough game, inherits boardgame::Board.
*
*   Holds the board for the mega breakthrough game.
*/
class Board : public boardgame::breakthrough::Board {
public:
    /*! \brief Board constructor
    *
    *   @param player1  Player one.
    *   @oaram player2  Player two.
    *   @param width    the width of the board.
    *   @param height   the height of the board.
    */
    explicit Board(Player* player1, Player* player2, int width, int height);
    /*! \brief ~Board destructor
    */
    virtual ~Board();

    /*! \fn initialize
    *   \brief initializes the board, with pieces for each player.
    *
    *   @param player1  Player one.
    *   @param player2  Player two.
    */
    virtual void initialize(Player* player1, Player* player2);
};

}}

#endif