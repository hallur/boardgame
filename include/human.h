#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include <string>

class Human : public Player {
public:
    explicit Human(std::string name) : Player(name) {};
    virtual void playTurn();
};

#endif