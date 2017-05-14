#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H

#include "game.h"
#include "player.h"

#include <string>
#include <vector>

namespace boardgame {

class GameConsole {
public:
    explicit GameConsole();
    virtual ~GameConsole();

    std::string getCommandFromUser() const;
    bool executeCommand(std::string command);
private:
    void list() const;
    void game(const int& n, Player* player1, Player* player2);
    void start() const;
    void legal() const;
    void move(const std::string& from, const std::string& to) const;
    void retract() const;
    void display() const;
    void evaluate() const;
    void go() const;
    void level(std::string difficulty) const;
    void debug() const;

    std::vector<std::string> splitCommand(const std::string& command) const;
    bool strIsPosInt(const std::string& str) const;
    Player* parsePlayerStr(const std::string& str) const;

    Game* game_;
};
    
}

#endif