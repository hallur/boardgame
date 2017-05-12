#include "human.h"
#include "random.h"
#include "foxandhound/game.h"

#include <iostream>

int main(int argc, char **argv) {
    auto player1 = new boardgame::Human("Player 1");
    auto player2 = new boardgame::Human("Player 2");

    auto game = boardgame::foxandhound::Game(player1, player2);

    do {
        game.display();
        game.playTurn();
        game.switchCurrentPlayer();
    } while (!game.getWinner());

    return 0;
}