#include "easy.h"
#include "board.h"

#include <vector>
#include <stdlib.h>

boardgame::Easy::Easy(std::string name) : boardgame::Computer(name) {}

boardgame::Easy::~Easy() {}

void boardgame::Easy::playTurn(boardgame::Board* board) {
    std::vector<boardgame::Move> legalMoves;
    std::vector<boardgame::Move> desiredMoves;
    for ( auto start : board->getPiecesLocationFor(this) ) {
        for ( auto destination : board->getLegalMovesFor(start) ) {
            if ( board->getPieceAt(destination)) {
                desiredMoves.push_back(Move(start, destination));
            }
            else {
                legalMoves.push_back(Move(start, destination));
            }
        }
    }
    if ( !desiredMoves.empty() ) {
        int i = rand() % desiredMoves.size();
        try {
            board->movePiece(desiredMoves[i].from, desiredMoves[i].to);
        } catch (...) {
            
        }
    }
    else {
        int i = rand() % legalMoves.size();
        try {
            board->movePiece(legalMoves[i].from, legalMoves[i].to);
        } catch (...) {
            
        }
    }
}