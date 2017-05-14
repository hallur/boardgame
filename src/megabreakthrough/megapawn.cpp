#include "megabreakthrough/megapawn.h"

boardgame::megabreakthrough::MegaPawn::MegaPawn(boardgame::Player* player, bool top) : boardgame::Piece(player, (top ? 'm' : 'M')) {
    moveRules_.push_back(MoveRule( 1, (top ? 1 : -1), false, false, false ));  // top-right
    moveRules_.push_back(MoveRule(  0, (top ? 1 : -1), false, false, false ));  // up
    moveRules_.push_back(MoveRule(  0, (top ? 2 : -2), true, false, false, 2 ));  // up up
    moveRules_.push_back(MoveRule( -1, (top ? 1 : -1), false, false, false ));  // top-left
    moveRules_.push_back(MoveRule( -1, (top ? 1 : -1), false, true, false ));   // top-left kill
    moveRules_.push_back(MoveRule(  1, (top ? 1 : -1), false, true, false ));   // top-right kill
}

boardgame::megabreakthrough::MegaPawn::~MegaPawn() {}