#ifndef FOXANDHOUND_HOUND_H
#define FOXANDHOUND_HOUND_H

/*! \file hound.h
*   \brief file wich holds the hound peace used in fox and hounds.
*
*   The hound is a piece used in the fox and hounds game, and inherits the Piece class. 
*/

#include "../piece.h"

namespace boardgame {
namespace foxandhound {


/*! \class Hound
*   \breif Hound class for the pwan Piece, inherits the boardgame::Piece.
*
*   Piece used in the fox and hounds game.
*/
class Hound : public boardgame::Piece {
public:
    /*! \breif Hound constructor
    *
    *   Creates a hound.
    *
    *   @param player Owner of the piece
    */
    explicit Hound(boardgame::Player* player);
    /*! \breif ~Hound destructor
    */
    virtual ~Hound();
};

}}

#endif