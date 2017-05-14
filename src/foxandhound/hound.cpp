#include "foxandhound/hound.h"

boardgame::foxandhound::Hound::Hound(boardgame::Player* player) : boardgame::Piece(player, 'H') {
    moveRules_.push_back(MoveRule(  1,  1, false, false, false )); // bottom-right
    moveRules_.push_back(MoveRule( -1,  1, false, false, false ));  // bottom-left
}

boardgame::foxandhound::Hound::~Hound() {}