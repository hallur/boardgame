#include "game.h"
#include <iostream>

int main(int argc, char **argv) {
    boardgame::Game game;
    game.initialize();

    while (!game.getWinner()) {
        game.printBoard();
        game.playTurn();
    }

    return 0;
}