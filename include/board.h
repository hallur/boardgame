#ifndef BOARD_H
#define BOARD_H

/*! \file board.h
*   \brief contains the board class for games
*/


#include "structs.h"
#include "piece.h"

#include <utility>
#include <vector>
#include <stack>

namespace boardgame {

class Board {
public:
    explicit Board(const int& width, const int& height);
    virtual ~Board();

    int getHeight() const;
    Piece* getPieceAt(Location location) const;
    std::vector<Location> getLegalMovesFor(Location) const;

    virtual void initialize(Player* player1, Player* player2) = 0;
    void movePiece(Location from, Location to, Player* player);
    int countPiecesFor(Player* player) const;
    std::vector<Location> getPieceLocationsFor(Player* player) const;
    void retract();

    friend std::ostream& operator<<(std::ostream& os, const Board& rhs);

protected:
    Piece*** pieces_;
    int width_;
    int height_;
    std::stack<Piece*> graveyard_;
    std::stack<MoveHistoryState> moveHistory_; 
};

std::ostream& operator<<(std::ostream& os, const Board& rhs);

}

#endif