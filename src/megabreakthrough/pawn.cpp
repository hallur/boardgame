#include "megabreakthrough/pawn.h"

boardgame::megabreakthrough::Pawn::Pawn(boardgame::Player* player, bool top) : boardgame::Piece(player, (top ? 'p' : 'P')) {
    moveRules_.push_back(MoveRule(  1, (top ? 1 : -1), false, false, false ));  // top-right
    moveRules_.push_back(MoveRule(  0, (top ? 1 : -1), false, false, false ));  // up
    moveRules_.push_back(MoveRule( -1, (top ? 1 : -1), false, false, false ));  // top-left
    moveRules_.push_back(MoveRule( -1, (top ? 1 : -1), false, true, false ));   // top-left kill
    moveRules_.push_back(MoveRule(  1, (top ? 1 : -1), false, true, false ));   // top-right kill
}

boardgame::megabreakthrough::Pawn::~Pawn() {}