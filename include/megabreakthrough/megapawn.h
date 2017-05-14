#ifndef MEGABREAKTHROUGH_MEGAPAWN_H
#define MEGABREAKTHROUGH_MEGAPAWN_H

/*! \file megapawn.h
*   \brief file wich holds the mega pawn peace used in mega breakthrough.
*
*   The mega pawn is a piece used in the mega breakthrough game, and inherits the breakthrough::Pawn class.
*/

#include "../breakthrough/pawn.h"

namespace boardgame {
namespace megabreakthrough {

/*! \class MegaPawn
*   \brief MegaPawn class for the mega pawn Piece, inherits the boardgame::breakthrough::Pawn.
*
*   Piece used in the breakthrough game. We inherit boardgame::breakthrough::Pawn becuase Pawn and
*   MegaPawn are almost the same the only difference is that The MegaPawn has one more move, (and 
*   whe want to be able identify them with different markers).
*/
class MegaPawn : public boardgame::breakthrough::Pawn {
public:
    /*! \brief MegaPawn constructor
    *
    *   Creates a mega pawn.
    *
    *   @param top      if the MegaPawn is on top of the board or bottom
    *   @param player   Owner of the piece
    */
    explicit MegaPawn(boardgame::Player* player, bool top);
    /*! \brief ~MegaPawn destructor
    */
    virtual ~MegaPawn();
};

}}

#endif