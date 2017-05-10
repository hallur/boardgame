#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include <string>

namespace boardgame {

class Human : public Player {
public:
    explicit Human(std::string name);
    virtual ~Human();
    virtual void playTurn();
};

}

#endif