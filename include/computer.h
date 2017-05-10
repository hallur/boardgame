#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include <string>

namespace boardgame {

enum class Difficulty { random, easy, medium, hard };

class Computer : public Player {
public:
    explicit Computer(std::string name);
    virtual ~Computer();
    virtual void playTurn();
private:
    Difficulty difficulty_;
};

}

#endif