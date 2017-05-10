#include "human.h"
#include "game.h"

int main(int argc, char **argv) {
    boardgame::Player* player1 = new boardgame::Human("Player1");
    boardgame::Player* player2 = new boardgame::Human("Player2");

    boardgame::Game game(player1, player2);
    //game.initialize();

    while (!game.getWinner()) {
        game.printBoard();
        game.playTurn();
    }

    return 0;
}