#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

/*! \file exceptions.h
*   \brief Holds custoum exceptions
*
*   contains all custoum exceptions for boardgames.
*/

namespace boardgame {

/*! \class boardgame_exception
*   \brief Parent class for custoum boardgame exceptions
*
*   pure virtual class that should be a base class for all boardgame coustom exceptions
*/
class boardgame_exception : public std::exception {
public: 
    virtual const char* what() const throw() = 0; //!< pure virtual function that will be used for custom exceptions
};

/*! \class illegal_move_exception
*   \brief Illegal move exception derived from boardgame exception
*
*   thrown when a player attemts to do an illegal move
*/
class illegal_move_exception : public boardgame_exception {
public:
    virtual const char* what() const throw() {
        return "Illegal move.";
    }
};

}

#endif