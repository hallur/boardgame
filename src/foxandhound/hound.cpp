#include "foxandhound/hound.h"

boardgame::foxandhound::Hound::Hound(boardgame::Player* player) : boardgame::Piece(player, 'H') {
    moveRules_ = {
        {  1,  1, false, false, false }, // bottom-right
        { -1,  1, false, false, false }  // bottom-left
    };
}

boardgame::foxandhound::Hound::~Hound() {}