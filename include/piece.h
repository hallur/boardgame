#ifndef PIECE_H
#define PIECE_H

#include "player.h"

#include <string>
#include <utility>
#include <vector>

namespace boardgame {

class Piece {
public:
    explicit Piece(const char& marker, Player* player);
    virtual ~Piece();

    friend std::ostream& operator<<(std::ostream& os, const Piece& rhs);
protected:
private:
    char marker_;
    Player* player_;
    std::vector<std::pair<int, int> > moves_;
    std::vector<std::pair<int, int> > killMoves_;
};

std::ostream& operator<<(std::ostream& os, const Piece& rhs);

}

#endif