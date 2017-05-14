#include "foxandhound/fox.h"

boardgame::foxandhound::Fox::Fox(boardgame::Player* player) : boardgame::Piece(player, 'f') {
    moveRules_.push_back(MoveRule(  1, -1, false, false, false )); // top-right
    moveRules_.push_back(MoveRule(  1,  1, false, false, false )); // bottom-right
    moveRules_.push_back(MoveRule( -1,  1, false, false, false )); // bottom-left
    moveRules_.push_back(MoveRule( -1, -1, false, false, false ));  // top-left
}

boardgame::foxandhound::Fox::~Fox() {}