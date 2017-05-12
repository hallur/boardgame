#include "human.h"
#include "board.h"
#include "exceptions.h"


#include <string>
#include <iostream>

boardgame::Human::Human(std::string name) : boardgame::Player(name) {}

boardgame::Human::~Human() {}

void boardgame::Human::playTurn(boardgame::Board* board) {

    bool invalidInput = true;
    while(invalidInput){
        try {
            // todo: handle invalid input
            std::string fromStr, toStr;
            std::cin >> fromStr >> toStr;

            boardgame::Location fromLoc;
            fromLoc.x = static_cast<int>(fromStr[0]) - 97;
            fromLoc.y = static_cast<int>(fromStr[1]) - 48;

            boardgame::Location toLoc;
            toLoc.x = static_cast<int>(toStr[0]) - 97;
            toLoc.y = static_cast<int>(toStr[1]) - 48;

            boardgame::Move turn;
            turn.from = fromLoc;
            turn.to = toLoc;

            turn.from.y = board->getHeight() - turn.from.y;
            turn.to.y = board->getHeight() - turn.to.y;
            board->movePiece(turn.from, turn.to);

            invalidInput = false;
        } catch (std::out_of_range& e) {
            std::cout << "Out of Range error: " << e.what() << std::endl;
        } catch(boardgame::illegal_move_exception& e) {
            std::cout << e.what() << std::endl;
        }catch (...) {
            std::cerr << "An unknown error has accured! When moving." << std::endl;
            throw;
        }
    }
}