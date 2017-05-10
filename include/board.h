#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <vector>
#include <utility>

namespace boardgame {

class Board {
public:
    explicit Board(const int& width, const int& height);
    virtual ~Board();

    Piece* getPiece(const int& x, const int& y) const;

    virtual bool move(Piece* from, Piece* to);
    virtual std::vector<Piece*> getLegalMoves(Piece* piece) const;

    friend std::ostream& operator<<(std::ostream& os, const Board& rhs);

private:
    Piece*** pieces_;
    int width_;
    int height_;
};

std::ostream& operator<<(std::ostream& os, const Board& rhs);

}

#endif