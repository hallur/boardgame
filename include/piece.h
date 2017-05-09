#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <utility>
#include <vector>

class Piece {
public:
    explicit Piece(const char& marker, std::string* player);
    virtual ~Piece();

    friend std::ostream& operator<<(std::ostream& os, const Piece& rhs);
protected:
private:
    char marker_;
    std::string* player_;
    std::vector<std::pair<int, int> > moves_;
    std::vector<std::pair<int, int> > killMoves_;
};

#endif