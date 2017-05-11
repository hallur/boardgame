#ifndef FOXANDHOUND_BOARD_H
#define FOXANDHOUND_BOARD_H

#include "../board.h"

namespace boardgame {
namespace foxandhound {

class Board : public boardgame::Board {
public:
    explicit Board(Player* player1, Player* player2);
    explicit Board(const foxandhound::Board&);
    virtual ~Board();

    virtual void initialize(Player* player1, Player* player2);
    Location getFoxLocation() const;
    Location* getHoundLocations() const;
};

}}

#endif