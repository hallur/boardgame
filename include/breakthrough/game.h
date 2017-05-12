#ifndef BREAKTHROUGH_GAME_H
#define BREAKTHROUGH_GAME_H

#include "../game.h"

namespace boardgame {
namespace breakthrough {

class Game : public boardgame::Game {
public:
    explicit Game(boardgame::Player* player1, boardgame::Player* player2, int width = 8, int height = 8);
    virtual ~Game();

    virtual boardgame::Player* getWinner() const;
};

}}

#endif