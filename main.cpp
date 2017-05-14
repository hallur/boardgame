#include "human.h"
#include "random.h"
#include "easy.h"
#include "foxandhound/game.h"
#include "breakthrough/game.h"
#include "megabreakthrough/game.h"

#include <string> 
#include <iostream>

int main(int argc, char **argv) {
    auto player1 = new boardgame::Easy("Player 1");
    auto player2 = new boardgame::Easy("Player 2");

    /*auto game = boardgame::foxandhound::Game(player1, player2);

    do {
        game.display();
        game.playTurn();
        game.switchCurrentPlayer();
    } while (!game.getWinner());*/

    auto breakthrough = boardgame::megabreakthrough::Game(player1, player2);

    do {
        breakthrough.display();
        std::string str;
        std::cin >> str;
        breakthrough.playTurn();
        breakthrough.switchCurrentPlayer();
    } while (!breakthrough.getWinner());
    breakthrough.display();
    std::cout << "We have a winner!" << std::endl;
    std::string str;
    std::cin >> str;
    return 0;
}