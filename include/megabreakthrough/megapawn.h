#ifndef MEGABREAKTHROUGH_MEGAPAWN_H
#define MEGABREAKTHROUGH_MEGAPAWN_H

/*! \file megapawn.h
*   \brief file wich holds the mega pawn peace used in mega breakthrough.
*
*   The mega pawn is a piece used in the mega breakthrough game, and inherits the Piece class. 
*/

#include "../breakthrough/pawn.h"

namespace boardgame {
namespace megabreakthrough {

class MegaPawn : public boardgame::breakthrough::Pawn {
public:
    /*! \breif MegaPawn constructor
    *
    *   Creates a pawn.
    *
    *   @param top if the Pawn is on top of the board or bottom
    *   @param player Owner of the piece
    */
    explicit MegaPawn(boardgame::Player* player, bool top);
    /*! \breif ~MegaPawn destructor
    */
    virtual ~MegaPawn();
};

}}

#endif