#ifndef FOXANDHOUND_BOARD_H
#define FOXANDHOUND_BOARD_H

/*! \file /boardgame/include/foxandhound/board.h
*   \brief file wich holds the board for foxandhound game.
*
*   The board inherits from our base boardgame::Board class, and implements some
*   additional features for the foxandhound game.
*/

#include "../board.h"

namespace boardgame {
namespace foxandhound {

/*! \class Board
*   \brief Board for fox and hounds game, inherits boardgame::Board.
*
*   Holds the board for the fox and hounds game.
*/
class Board : public boardgame::Board {
public:
    /*! \brief Board constructor
    *
    *   @param player1  Player one.
    *   @param player2  Player two.
    */
    explicit Board(Player* player1, Player* player2);
    /*! \brief Board copy-constructor
    *
    *   @param rhs  board to be copied.
    */
    explicit Board(const foxandhound::Board& rhs);
    /*! \brief ~Board destructor
    */
    virtual ~Board();

    /*! \fn virtual void boardgame::foxandhound::Board::initialize(Player *player1, Player *player2)
    *   \brief initializes the board, with pieces for each player.
    *
    *   @param player1  Player one.
    *   @param player2  Player two.
    */
    virtual void initialize(Player* player1, Player* player2);
    /*! \fn getFoxLocation
    *   \brief gets the location of the fox.
    *
    *   returns a Location of the fox.
    */
    Location getFoxLocation() const;
    /*! \fn getHoundLocations
    *   \brief gets the location of the hounds.
    *
    *   returns a Location array of the hounds.
    */
    Location* getHoundLocations() const;
};

}}

#endif