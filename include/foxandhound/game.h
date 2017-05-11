#ifndef FOXANDHOUND_GAME_H
#define FOXANDHOUND_GAME_H

#include "../game.h"

namespace boardgame {
namespace foxandhound {

class Game : public boardgame::Game {
public:
    explicit Game(boardgame::Player* player1, boardgame::Player* player2);
    virtual ~Game();

    virtual boardgame::Player* getWinner() const;
};

}}

#endif