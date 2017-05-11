#ifndef BOARD_H
#define BOARD_H

/*! \file board.h
*   \breif contains the board class for games
*/


#include "structs.h"
#include "piece.h"

#include <utility>
#include <vector>

namespace boardgame {

class Board {
public:
    explicit Board(const int& width, const int& height);
    virtual ~Board();

    virtual void initialize(Player* player1, Player* player2) = 0;
    Piece* getPieceAt(Location location) const;
    void movePiece(Location from, Location to);
    std::vector<Location> getLegalMovesFor(Location) const;

    friend std::ostream& operator<<(std::ostream& os, const Board& rhs);

protected:
    Piece*** pieces_;
    int width_;
    int height_;
};

std::ostream& operator<<(std::ostream& os, const Board& rhs);

}

#endif