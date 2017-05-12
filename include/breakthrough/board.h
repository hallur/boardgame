#ifndef BREAKTHROUGH_BOARD_H
#define BREAKTHROUGH_BOARD_H

#include "../board.h"

namespace boardgame {
namespace breakthrough {

class Board : public boardgame::Board {
public:
    explicit Board(Player* player1, Player* player2, int width, int height);
    explicit Board(const breakthrough::Board&);
    virtual ~Board();

    virtual void initialize(Player* player1, Player* player2);

    Player* playerOnWinningTile(Player* player1, Player* player2);
};

}}

#endif