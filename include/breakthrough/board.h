#ifndef BREAKTHROUGH_BOARD_H
#define BREAKTHROUGH_BOARD_H

/*! \file /boardgame/include/breakthrough/board.h
*   \brief file wich holds the board for breakthrough game.
*
*   The board inherits from our base boardgame::Board class, and implements some
*   additional features for the breakthrough game.
*/

#include "../board.h"

namespace boardgame {
namespace breakthrough {

/*! \class Board
*   \brief Board for breakthrough game, inherits boardgame::Board.
*
*   Holds the board for the breakthrough game.
*/
class Board : public boardgame::Board {
public:
    /*! \brief Board constructor.
    *
    *   @param player1  Player one.
    *   @param player2  Player two.
    *   @param width    the width of the board.
    *   @param height   the height of the board.
    */
    explicit Board(Player* player1, Player* player2, int width, int height);
    /*! \brief Board copy-constructor
    *
    *   @param rhs  board to be copied.
    */
    explicit Board(const breakthrough::Board& rhs);
    /*! \brief ~Board destructor
    */
    virtual ~Board();

    /*! \fn virtual void boardgame::breakthrough::Board::initialize(Player *player1, Player *player2)
    *   \brief initializes the board, with pieces for each player.
    *
    *   @param player1  Player one.
    *   @param player2  Player two.
    */
    virtual void initialize(Player* player1, Player* player2);

    /*! \fn playerOnWinningTile
    *   \brief gets the player that has reached the other side.
    *
    *   @param player1  Player one.
    *   @param player2  Player two.
    */
    Player* playerOnWinningTile(Player* player1, Player* player2);
};

}}

#endif