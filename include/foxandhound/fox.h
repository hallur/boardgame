#ifndef FOXANDHOUND_FOX_H
#define FOXANDHOUND_FOX_H

#include "../piece.h"

namespace boardgame {
namespace foxandhound {

class Fox : public boardgame::Piece {
public:
    explicit Fox(boardgame::Player* player);
    virtual ~Fox();
};

}}

#endif