#ifndef MEGABREAKTHROUGH_BOARD_H
#define MEGABREAKTHROUGH_BOARD_H

#include "../board.h"

namespace boardgame {
namespace megabreakthrough {

class Board : public boardgame::Board {
public:
    explicit Board(Player* player1, Player* player2, int width, int height);
    explicit Board(const megabreakthrough::Board&);
    virtual ~Board();

    virtual void initialize(Player* player1, Player* player2);

    Player* playerOnWinningTile(Player* player1, Player* player2);
};

}}

#endif