#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include <string>

class Computer : public Player {
public:
    explicit Computer(std::string name) : Player(name) {};
    virtual void playTurn();
};

#endif