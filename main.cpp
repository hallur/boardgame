#include "game.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    Game game;
    game.initialize();

    while (!game.getWinner()) {
        game.printBoard();
        game.playTurn();
    }

    return 0;
}