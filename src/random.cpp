#include "random.h"

#include <stdlib.h>

boardgame::Random::Random(std::string name) : boardgame::Computer(name) {}

boardgame::Random::~Random() {}

void boardgame::Random::playTurn(boardgame::Board* board) {
    std::vector<boardgame::Move> legalMoves;
    for ( auto start : board->getPiecesLocationFor(*this) ) {
        for ( auto destination : board->getLegalMovesFor(location) ) {
            legalMoves.push_back(start, destination);
        }
    }
    int i = rand() % legalMoves.size();
    try {
        board->movePiece(legalMoves[i].from, legalMoves[i].to);
    } catch (...) {
        
    }
}