#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    explicit Player(std::string name) : name_(name) {};
    virtual void playTurn() = 0;
protected:
    std::string name_;
};

#endif