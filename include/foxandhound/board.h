#ifndef FOXANDHOUND_BOARD_H
#define FOXANDHOUND_BOARD_H

#include "../board.h"

namespace boardgame {
namespace foxandhound {

class Board : public boardgame::Board {
public:
    explicit Board(boardgame::Player* player1, boardgame::Player* player2);
    virtual ~Board();

    virtual void initialize(boardgame::Player* player1, boardgame::Player* player2);
    Location getFoxLocation() const;
    Location* getHoundLocations() const;
};

}}

#endif