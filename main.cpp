#include "gameconsole.h"

int main(int argc, char **argv) {
    boardgame::GameConsole console;
    bool run = true;
    while (run) {
        auto command = console.getCommandFromUser();
        run = console.executeCommand(command);
    }
}