#include "megabreakthrough/megapawn.h"

boardgame::megabreakthrough::MegaPawn::MegaPawn(boardgame::Player* player, bool top) : boardgame::breakthrough::Pawn(player, top, 'm') {
    moveRules_.push_back(MoveRule(  0, (top ? 1 : -1), true, false, false, 2 ));  // up up
}

boardgame::megabreakthrough::MegaPawn::~MegaPawn() {}