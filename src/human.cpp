#include "human.h"

#include <string>
#include <iostream>

boardgame::Human::Human(std::string name) : boardgame::Player(name) {}

boardgame::Human::~Human() {}

boardgame::Move boardgame::Human::playTurn() {
    // todo: handle invalid input
    std::string fromStr, toStr;
    std::cin >> fromStr >> toStr;

    boardgame::Location fromLoc;
    fromLoc.x = static_cast<int>(fromStr[0]) - 97;
    fromLoc.y = static_cast<int>(fromStr[1]);

    boardgame::Location toLoc;
    toLoc.x = static_cast<int>(toStr[0]) - 97;
    toLoc.y = static_cast<int>(toStr[1]);

    boardgame::Move move;
    move.from = fromLoc;
    move.to = toLoc;
    return move;
}