#include "computer.h"

boardgame::Computer::Computer(std::string name, boardgame::Difficulty difficulty) : boardgame::Player(name), difficulty_(difficulty) {}

boardgame::Computer::~Computer() {}

boardgame::Move boardgame::Computer::playTurn() {
    // todo: implement this function, calculate move
    boardgame::Move move;
    return move;
}