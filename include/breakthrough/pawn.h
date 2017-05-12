#ifndef BREAKTHROUGH_PAWN_H
#define BREAKTHROUGH_PAWN_H

#include "../piece.h"

namespace boardgame {
namespace breakthrough {

class Pawn : public boardgame::Piece {
public:
    /*! \breif Pawn constructor
    *   Creates a pawn.
    *   @param top if the Pawn is on top of the board or bottom
    *   @param player Owner of the piece
    */
    explicit Pawn(boardgame::Player* player, bool top);
    virtual ~Pawn();
};

}}

#endif