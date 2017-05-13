#include "megabreakthrough/megapawn.h"

boardgame::megabreakthrough::MegaPawn::MegaPawn(boardgame::Player* player, bool top) : boardgame::Piece(player, (top ? 'm' : 'M')) {
    moveRules_ = {
        {  1, (top ? 1 : -1), false, false, false },  // top-right
        {  0, (top ? 1 : -1), false, false, false },  // up
        {  0, (top ? 2 : -2), true, false, false },  // up up
        { -1, (top ? 1 : -1), false, false, false },  // top-left
        { -1, (top ? 1 : -1), false, true, false },   // top-left kill
        {  1, (top ? 1 : -1), false, true, false },   // top-right kill
    };
}

boardgame::megabreakthrough::MegaPawn::~MegaPawn() {}