#ifndef MEGABREAKTHROUGH_BOARD_H
#define MEGABREAKTHROUGH_BOARD_H

#include "../breakthrough/board.h"

namespace boardgame {
namespace megabreakthrough {

class Board : public boardgame::breakthrough::Board {
public:
    explicit Board(Player* player1, Player* player2, int width, int height);
    virtual ~Board();

    virtual void initialize(Player* player1, Player* player2);
};

}}

#endif