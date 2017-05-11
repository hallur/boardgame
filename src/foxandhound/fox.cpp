#include "foxandhound/fox.h"

boardgame::foxandhound::Fox::Fox(boardgame::Player* player) : boardgame::Piece(player, 'f') {
    moveRules_ = {
        {  1, -1, false, false, false }, // top-right
        {  1,  1, false, false, false }, // bottom-right
        { -1,  1, false, false, false }, // bottom-left
        { -1, -1, false, false, false }  // top-left
    };
}

boardgame::foxandhound::Fox::~Fox() {}