#ifndef STRUCTS_H
#define STRUCTS_H

/*! \file structs.h
*   \brief Contains structs used in boardgames
*/

namespace boardgame {

/*! \struct Location
*   \brief Holds a x,y location on a 2d grid.
*/
struct Location {
    int x; //!< the X location on a grid.
    int y;  //!< the Y location on a grid.
    /*! \brief Default location costructor x and y 0
    */
    explicit Location() : Location(0, 0) {};
    /*! \brief Location cosntructor
    *
    *   sets X and Y.
    *
    *   @param x the X location on a grid.
    *   @param y the Y location on a grid.
    */
    explicit Location(const int& x, const int& y) : x(x), y(y) {};
    /*! \brief == operator for Location
    *
    *   returns true iff x and y are equal.
    */
    bool operator==(const Location& rhs) { return (x == rhs.x && y == rhs.y); }
};

/*! \struct Move
*   \brief holds two Locations.
*
*   Holds a starting Location and an arrival location.
*   used to pass Moves around that players are making / trying to make.
*/
struct Move {
    Location from; //!< Location from, holds the starting location.
    Location to; //!< Location to, holds the arrival locaton.
    /* \brief Move cosntructor
    *
    *   Creates a move with two default locations.
    */
    explicit Move() : Move(Location(), Location()) {};
    /* \brief Move constructor that takes locations
    *
    *   creates a new move with the two locations provided.
    *
    *   @param from starting Location.
    *   @param to   destination Location.
    */
    explicit Move(const Location& from, const Location& to) : from(from), to(to) {};
};

/*! \struct MoveHistoryState
*   \brief holds what happend when a move was performed on a board.
*
*   When a move is performed on a board we want to know what happend and store it so we can revert,
*   what happend.
*/
struct MoveHistoryState {
    Move move; //!< The move that was performed.
    bool kill; //!< If a piece was killed when performing this move.
    /* \brief MoveHistoryState constructor
    *
    *   with default move and kill being false.
    */
    explicit MoveHistoryState() : MoveHistoryState(Move()) {}
    /* \brief MoveHistoryState constructor with parameters.
    *
    *   Sets the move to given move and kill if kill is given else it is set to false.
    *
    *   @param move the Move that was performed.
    *   @param kill if a piece was killed or not.
    */
    explicit MoveHistoryState(const Move& move, bool kill = false) : move(move), kill(kill) {}
};

/*! \struct MoveRule
*   \brief Rule about how a Piece can move.
*
*   used to define one way how a peace can move.
*/
struct MoveRule {
    int xDiff; //!< difference beetween current x possition and x possition after movement
    int yDiff; //!< difference beetween current y possition and y possition after movement
    bool continuous; //!< can the piece move continuously, ex. bishop in chess 
    bool kill; //!< is this a killing move
    bool friendlyFire; //!< allows a peace to be killed by another peace with same owner
    int contLength; //!< if the Piece should not be able to move continuosly forever (only move 5 steps forward...) if < 1 no limit
    bool firstMove; //!< if the Move is only available when the Piece hasn't been moved before.
    int moved; //!< holds how may times a piece has been moved
    /* \brief MoveRule constructor
    *
    *   creates a new move rule and sets all parameters that are defined, if they are not defined they will be set to their defaults.
    *
    *   @param xDiff            the difference beetween current x possition and x possition after movement. Defualt 0.
    *   @param yDiff            the difference beetween current y possition and y possition after movement. Default 0.
    *   @param continuous       if the Piece can move continuoisly. Default false.
    *   @param kill             if the Piece can kill with the current move. Default false.
    *   @param friendlyFire     if the Pice can kill other Pieces with the same owener.
    *   @param contLengt        the lenght of the continuous movement. Default -1 (infinite).
    *   @param firstMove        if the move is only performable as a first move. 
    */
    explicit MoveRule(const int& xDiff = 0, const int& yDiff = 0, const bool& continuous = false, const bool& kill = false, const bool& friendlyFire = false, const int& contLength = -1, const bool& firstMove = false) :
        xDiff(xDiff), yDiff(yDiff), continuous(continuous), kill(kill), friendlyFire(friendlyFire), contLength(contLength), firstMove(firstMove), moved(0) {};
};
}

#endif