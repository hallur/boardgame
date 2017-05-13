#include "megabreakthrough/pawn.h"

boardgame::megabreakthrough::Pawn::Pawn(boardgame::Player* player, bool top) : boardgame::Piece(player, (top ? 'p' : 'P')) {
    moveRules_ = {
        {  1, (top ? 1 : -1), false, false, false },  // top-right
        {  0, (top ? 1 : -1), false, false, false },  // up
        { -1, (top ? 1 : -1), false, false, false },  // top-left
        { -1, (top ? 1 : -1), false, true, false },   // top-left kill
        {  1, (top ? 1 : -1), false, true, false },   // top-right kill
    };
}

boardgame::megabreakthrough::Pawn::~Pawn() {}