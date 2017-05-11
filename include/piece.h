#ifndef PIECE_H
#define PIECE_H

/*! \file piece.h
*   \brief Contains base class for Pieces in board game.
*/

#include "structs.h"
#include "player.h"

#include <string>
#include <utility>
#include <vector>

namespace boardgame {

/*! \class Piece
*   \brief each piece represented by this class
*   the class holds, everything a piece needs to function on a board, owner of the peace, how it is represented
*   and how it can move on a board.
*/
class Piece {
public:
    /*! \brief Piece constructor
    *   Creates a peace.
    *   @param marker Character that will represent the piece on the board
    *   @param player Owner of the piece
    */
    explicit Piece(Player* player, const char& marker);
    /*! \brief Piece destructor
    *   destructor
    */
    virtual ~Piece() = 0;
    char getMarker() const; // todo: document this function
    /*! \brief Piece getPlayer
    *   returns owner of the piece
    */
    Player* getPlayer() const;
    /*! \brief Piece setPlayer
    *   changes the owner of a piece, usefull if a game has some way of taking controll over enemys
    *   @param player new owner
    */
    void setPlayer(Player* player);
    /*! \brief Piece getMoveRules
    *   retunrs all move rules a piece has in a vector
    */
    std::vector<MoveRule> getMoveRules() const;
    /*! \brief Pice operator<<
    *   sets the piece marker into the ostream
    *   @param os the ostream
    *   @param rhs the Piece that will be printed  
    */
    friend std::ostream& operator<<(std::ostream& os, const Piece& rhs);
protected:
    char marker_; //!< stores the marker used to represent the piece for the player
    Player* player_; //!< owner of the piece
    std::vector<MoveRule> moveRules_; //!< holds a vector of MoveRules that define how a piece can move
};

std::ostream& operator<<(std::ostream& os, const Piece& rhs); // TODO:

}

#endif