#ifndef STRUCTS_H
#define STRUCTS_H

/*! \file structs.h
*   \brief Contains structs used in boardgames
*/

namespace boardgame {

// todo: document
struct Location {
    int x;
    int y;
    explicit Location() : Location(0, 0) {};
    explicit Location(const int& x, const int& y) : x(x), y(y) {};
    bool operator==(const Location& rhs) { return (x == rhs.x && y == rhs.y); }
};

// todo: document
struct Move {
    Location from;
    Location to;
    explicit Move() {};
    explicit Move(const Location& from, const Location& to) : from(from), to(to) {};
};
/*! \struct MoveRule
*   used to define one way how a peace can move.
*/
struct MoveRule {
    int xDiff; //!< difference weetween current x possition and x possition after movement
    int yDiff; //!< difference weetween current y possition and y possition after movement
    bool continuous; //!< can the piece move continuously, ex. bishop in chess 
    bool kill; //!< is this a killing move
    bool friendlyFire; //!< allows a peace to be killed by another peace with same owner
};
}

#endif