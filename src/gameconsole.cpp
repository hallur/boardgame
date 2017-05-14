#include "gameconsole.h"
#include "human.h"
#include "random.h"
#include "easy.h"
#include "foxandhound/game.h"
#include "breakthrough/game.h"
#include "megabreakthrough/game.h"
#include "exceptions.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

boardgame::GameConsole::GameConsole() : game_(nullptr) {}
boardgame::GameConsole::~GameConsole() { delete game_; }

void boardgame::GameConsole::list() const {
    std::cout << " # | Game" << std::endl;
    std::cout << "---|-------------------" << std::endl;
    std::cout << " 0 | Fox and Hounds" << std::endl;
    std::cout << " 1 | Breakthrough" << std::endl;
    std::cout << " 2 | Mega-Breakthrough" << std::endl;
}

void boardgame::GameConsole::game(const int& n, Player* player1, Player* player2) {
    // todo: implement this function
    if (n >= 0 && n <= 2) {
        if (game_) {
            delete game_;
        }
        if (n == 0) {
            game_ = new boardgame::foxandhound::Game(player1, player2);
        } else if (n == 1) {
            game_ = new boardgame::breakthrough::Game(player1, player2);
        } else if (n == 2) {
            game_ = new boardgame::megabreakthrough::Game(player1, player2);
        }
    } else {
        std::cout << "Error: Invalid value for parameter 'n'." << std::endl;
    }
}

void boardgame::GameConsole::start() const {
    if (game_) {
        game_->initialize(game_->getPlayer1(), game_->getPlayer2());
    } else {
        std::cout << "Unable to start; no game has been selected." << std::endl;
    }
}

void boardgame::GameConsole::legal() const {
    if (game_) {
        game_->printLegalMovesForCurrentPlayer();
    } else {
        std::cout << "Unable to print legal moves; there is no active game." << std::endl;
    }
}

void boardgame::GameConsole::move(const std::string& from, const std::string& to) const {
    /*if (game_) {
        if (from.length() == 2 && to.length() == 2) {
            boardgame::Location fromLoc;
            fromLoc.x = static_cast<int>(from[0]) - 97;
            fromLoc.y = game_->getBoard()->getHeight() - (static_cast<int>(from[1]) - 48);

            boardgame::Location toLoc;
            toLoc.x = static_cast<int>(to[0]) - 97;
            toLoc.y = game_->getBoard()->getHeight() - (static_cast<int>(to[1]) - 48);

            try {
                game_->getBoard()->movePiece(fromLoc, toLoc, game_->getCurrentPlayer());
                game_->switchCurrentPlayer();
            } catch (std::out_of_range& e) {
                std::cout << "Error: " << e.what() << std::endl;
            } catch (boardgame::illegal_move_exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            } catch (...) {
                std::cout << "Yikes! Unknown error!" << std::endl;
            }
        } else {
            std::cout << "Error: Invalid 'from' or 'to' parameter." << std::endl;
        }
    } else {
        std::cout << "Unable to move; there is no active game." << std::endl;
    }*/
}

void boardgame::GameConsole::retract() const {
    if (game_) {
        game_->retract();
    } else {
        std::cout << "Unable to retract; there is no active game." << std::endl;
    }
}

void boardgame::GameConsole::display() const {
    if (game_) {
        game_->display();
    } else {
        std::cout << "Unable to display; there is no active game." << std::endl;
    }
}

void boardgame::GameConsole::evaluate() const {
    // todo: implement this function
}

void boardgame::GameConsole::go() const {
    // todo: implement this function
}

void boardgame::GameConsole::level(std::string difficulty) const {
    // todo: implement this function
}

void boardgame::GameConsole::debug() const {
    // todo: implement this function
}

std::string boardgame::GameConsole::getCommandFromUser() const {
    std::string command;
    std::cout << "Command: ";
    getline(std::cin, command);
    return command;
}

std::vector<std::string> boardgame::GameConsole::splitCommand(const std::string& command) const {
    std::vector<std::string> result;
    std::stringstream ss(command);
    std::string item;
    while (ss >> item) {
        result.push_back(item);
    }
    return result;
}

bool boardgame::GameConsole::strIsPosInt(const std::string& str) const {
    for (auto it = str.begin(); it != str.end(); it++) {
        if (!isdigit(*it)) {
            return false;
        }
    }
    return true;
}

boardgame::Player* boardgame::GameConsole::parsePlayerStr(const std::string& playerStr) const {
    size_t colonIdx = playerStr.find(':');
    if (colonIdx != std::string::npos) {
        if (colonIdx != 0 && colonIdx != playerStr.length() - 1) { // if ':' is not the first or last char
            std::string playerType = playerStr.substr(0, colonIdx);
            if (playerType == "human") {
                std::string playerName = playerStr.substr(colonIdx + 1);
                return new boardgame::Human(playerName);
            } else if (playerType == "computer") {
                std::string difficulty = playerStr.substr(colonIdx + 1);
                if (difficulty == "random") {
                    return new boardgame::Random("Random Computer");
                } else if (difficulty == "easy") {
                    return new boardgame::Easy("Easy Computer");
                } else if (difficulty == "medium") {
                    std::cout << "Medium difficulty has not been implemented yet." << std::endl;
                } else if (difficulty == "hard") {
                    std::cout << "Hard difficulty has not been implemented yet." << std::endl;
                }
            } else {
                std::cout << "Invalid player format (expected e.g. 'human:John' or 'computer:easy')." << std::endl;
            }
        }
    } else {
        std::cout << "Invalid player format (expected e.g. 'human:John' or 'computer:easy'." << std::endl;
    }
    return nullptr;

}

bool boardgame::GameConsole::executeCommand(std::string command) {
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    auto commandBreakdown = splitCommand(command);
    auto front = commandBreakdown.front();
    if (front == "list") {
        list();
    } else if (front == "game") {
        if (commandBreakdown.size() >= 4) {
            int gameIdx = -1;
            auto gameIdxStr = commandBreakdown.at(1);
            if (strIsPosInt(gameIdxStr)) {
                gameIdx = std::stoi(gameIdxStr);
            } else {
                std::cout << "Error: Parameter 'n' for command 'game' must be a positive integer." << std::endl;
            }
            Player* player1 = parsePlayerStr(commandBreakdown.at(2));
            Player* player2 = parsePlayerStr(commandBreakdown.at(3));
            if (gameIdx != -1 && player1 && player2) {
                game(gameIdx, player1, player2);
            }
        } else {
            std::cout << "Command 'game' takes 3 parameters; 'gameIndex', 'player1' and 'player2'." << std::endl;
        }
    } else if (front == "start") {
        start();
    } else if (front == "legal") {
        legal();
    } else if (front == "move") {
        if (commandBreakdown.size() >= 3) {
            move(commandBreakdown.at(1), commandBreakdown.at(2));
        } else {
            std::cout << "Error: Command 'move' takes two parameters; 'from' and 'to'." << std::endl;
        }
    } else if (front == "retract") {
        retract();
    } else if (front == "display") {
        display();
    } else if (front == "evaluate") {
        evaluate();
    } else if (front == "go") {
        go();
    } else if (front == "level") {
        if (commandBreakdown.size() >= 2) {
            level(commandBreakdown.at(1));
        } else {
            std::cout << "Error: Missing parameter 'difficulty' for command 'level'." << std::endl;
        }
    } else if (front == "debug") {
        debug();
    } else if (front == "quit") {
        return false;
    } else {
        std::cout << "Error: Unknown command '" << command << "'." << std::endl;
    }
    return true;
}