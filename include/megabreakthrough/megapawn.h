#ifndef MEGABREAKTHROUGH_MEGAPAWN_H
#define MEGABREAKTHROUGH_MEGAPAWN_H

#include "../piece.h"

namespace boardgame {
namespace megabreakthrough {

class MegaPawn : public boardgame::Piece {
public:
    /*! \breif MegaPawn constructor
    *   Creates a pawn.
    *   @param top if the Pawn is on top of the board or bottom
    *   @param player Owner of the piece
    */
    explicit MegaPawn(boardgame::Player* player, bool top);
    virtual ~MegaPawn();
};

}}

#endif