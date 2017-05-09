#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <vector>
#include <utility>

class Board {
public:
    explicit Board();
    virtual ~Board();

    Piece* getPiece(const int& x, const int& y) const;

    virtual bool move(Piece* from, Piece* to);
    virtual std::vector<std::pair<Piece*, Piece*> > getLegalMoves(Piece* piece) const;

    friend std::ostream& operator<<(std::ostream& os, const Board& rhs);

protected:
    int getWidth() const;
    int getHeight() const;

private:
    std::vector<std::vector<Piece*> > pieces_;
};

#endif