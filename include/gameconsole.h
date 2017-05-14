#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H

/*! \file /boardgame/include/gameconsole.h
*   \brief Contains the class GameConsole
*/

#include "game.h"
#include "player.h"

#include <string>
#include <vector>

namespace boardgame {

/*! \class GameConsole
*   \brief GameConsole handles user input and executes commands
* 
*   Class that takes commands from the user and calls the appropriate functions
*/
class GameConsole {
public:
    /*! \brief GameConsole constructor
    *
    *   Creates a new instance of a GameConsole
    */
    explicit GameConsole();
    /*! \brief ~GameConsole destructor
    */
    virtual ~GameConsole();

    /*! \fn getCommandFromUser
    *
    *   \brief Takes a string from the standard input and returns it
    */
    std::string getCommandFromUser() const;
    /*! \fn executeCommand()
    *
    * \brief Takes a command as a parameter and executes it
    * 
    * @param command The command to execute
    */
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
