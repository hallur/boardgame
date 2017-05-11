#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

#include <utility>
#include <vector>

namespace boardgame {

struct Location {
    int x;
    int y;
    explicit Location() : Location(0, 0) {};
    explicit Location(const int& x, const int& y) : x(x), y(y) {};
    bool operator==(const Location& rhs) { return (x == rhs.x && y == rhs.y); }
};

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