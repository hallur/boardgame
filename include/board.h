#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <vector>
#include <utility>

namespace boardgame {

struct Location {
    int x;
    int y;
    bool operator==(const Location& rhs) { return (x == rhs.x && y == rhs.y); }
};

class Board {
public:
    explicit Board();
    explicit Board(const int& width, const int& height);
    virtual ~Board();

    Piece* getPieceAt(Location location) const;
    bool movePiece(Location from, Location to);
    std::vector<Location> getLegalMovesFor(Location) const;

    friend std::ostream& operator<<(std::ostream& os, const Board& rhs);

private:
    Piece*** pieces_;
    int width_;
    int height_;
};

std::ostream& operator<<(std::ostream& os, const Board& rhs);

}

#endif