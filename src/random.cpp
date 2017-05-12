#include "random.h"
#include "board.h"

#include <vector>
#include <stdlib.h>

boardgame::Random::Random(std::string name) : boardgame::Computer(name) {}

boardgame::Random::~Random() {}

void boardgame::Random::playTurn(boardgame::Board* board) {
    std::vector<boardgame::Move> legalMoves;
    for ( auto start : board->getPieceLocationsFor(this) ) {
        for ( auto destination : board->getLegalMovesFor(start) ) {
            legalMoves.push_back(Move(start, destination));
        }
    }
    int i = rand() % legalMoves.size();
    try {
        board->movePiece(legalMoves[i].from, legalMoves[i].to, this);
    } catch (...) {
        
    }
}