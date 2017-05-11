#ifndef FOXANDHOUND_HOUND_H
#define FOXANDHOUND_HOUND_H

#include "../piece.h"

namespace boardgame {
namespace foxandhound {

class Hound : public boardgame::Piece {
public:
    explicit Hound(boardgame::Player* player);
    virtual ~Hound();
};

}}

#endif