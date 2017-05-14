#ifndef BREAKTHROUGH_PAWN_H
#define BREAKTHROUGH_PAWN_H

/*! \file pawn.h
*   \brief file wich holds the pawn peace used in breakthrough.
*
*   The pawn is a piece used in the breakthrough game, and inherits the Piece class. 
*/

#include "../piece.h"

namespace boardgame {
namespace breakthrough {

/*! \class Pawn
*   \breif Pawn class for the pawn Piece, inherits the boardgame::Piece.
*
*   Piece used in the breakthrough game.
*/
class Pawn : public boardgame::Piece {
public:
    /*! \breif Pawn constructor
    *
    *   Creates a pawn.
    *
    *   @param top      if the Pawn is on top of the board or bottom
    *   @param player   Owner of the piece
    *   @param marker   the marker for the pawn p by default
    */
    explicit Pawn(boardgame::Player* player, bool top, char marker = 'p');
    /*! \breif ~Pawn destructor
    */
    virtual ~Pawn();
};

}}

#endif