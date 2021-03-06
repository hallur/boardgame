#ifndef MEGABREAKTHROUGH_BOARD_H
#define MEGABREAKTHROUGH_BOARD_H

/*! \file /boardgame/include/megabreakthrough/board.h
*   \brief file wich holds the board for mega breakthrough game.
*
*   The board inherits from our boardgame::breakthrough::Board class, since it is mostly
*   the same functionalaty except how the board gets intialized.
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
    *   @param player2  Player two.
    *   @param width    the width of the board.
    *   @param height   the height of the board.
    */
    explicit Board(Player* player1, Player* player2, int width, int height);
    /*! \brief ~Board destructor
    */
    virtual ~Board();

    /*! \fn virtual void boardgame::megabreakthrough::Board::initialize(Player *player1, Player *player2)
    *   \brief initializes the board, with pieces for each player.
    *
    *   @param player1  Player one.
    *   @param player2  Player two.
    */
    virtual void initialize(Player* player1, Player* player2);
};

}}

#endif