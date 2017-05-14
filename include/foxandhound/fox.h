#ifndef FOXANDHOUND_FOX_H
#define FOXANDHOUND_FOX_H

/*! \file fox.h
*   \brief file wich holds the fox peace used in fox and hounds.
*
*   The fox is a piece used in the fox and hounds game, and inherits the Piece class. 
*/

#include "../piece.h"

namespace boardgame {
namespace foxandhound {

/*! \class Fox
*   \brief Fox class for the pwan Piece, inherits the boardgame::Piece.
*
*   Piece used in the fox and hounds game.
*/
class Fox : public boardgame::Piece {
public:
    /*! \brief Fox constructor
    *
    *   Creates a fox.
    *
    *   @param player Owner of the piece
    */
    explicit Fox(boardgame::Player* player);
    /* \brief ~Fox destructor
    */
    virtual ~Fox();
};

}}

#endif