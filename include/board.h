#ifndef BOARD_H
#define BOARD_H

/*! \file board.h
*   \brief Contains the board class for games.
*   
*   The Board is used to hold together all gamestate information,
*   where each peace is and interactions with the peaces.
*/

#include "structs.h"
#include "piece.h"

#include <vector>
#include <stack>

namespace boardgame {

/*! \class Board
*   \brief Contains the board class for games.
*   
*   The Board is the class used to hold together all gamestate information,
*   where each peace is and interactions with the peaces. The class is pure virtual
*   and derived classes must implement the \fn initialize funciton, because the Board
*   has no idea some games might want their pieces set up on the board.
*/
class Board {
public:
    /*! \brief Board constructor
    *
    *   Creates a new board of specified size.
    *
    *   @param width    the widht of the board.
    *   @param height   the height of the board.
    */
    explicit Board(const int& width, const int& height);
    /*! \brief ~Board destructor
    */
    virtual ~Board();
    /*! \fn getHeight
    *   \brief returns the height of the board.
    */
    int getHeight() const;
    /*! \fn getPieceAt
    *   \brief returns the Piece* at a given location
    *
    *   returns nullptr if there is no Piece at the given location.
    *
    *   @param location the Location of the piece you want.
    */
    Piece* getPieceAt(Location location) const;
    /*! \fn getLegalMovesFor
    *   \brief returns legal moves for given location
    *
    *   returns a vector of Locations (destinations) for legal moves of a piece on a given location.
    *   used for example to check if player is trying to perofrm an illegal move, or to give the AI options of movement.
    *
    *   @param location the location you want legal moves for.
    */
    std::vector<Location> getLegalMovesFor(Location location) const;

    /*! \fn initialize
    *   \brief pure virtual function supposed to initialize the board
    *
    *   supposed to order the pieces on the board according to the game you are playing.
    *
    *   @param player1 player one.
    *   @param player2 player two.
    */
    virtual void initialize(Player* player1, Player* player2) = 0;
    /*! \fn movePiece
    *   \brief moves a piece for a player.
    *
    *   tries to move the piece from a given location to a given destination.
    *   used for moving pieces.
    *
    *   @param from     Location of the piece to be moved.
    *   @param to       destination Location.
    *   @param player   the player that is trying to move a piece.
    */
    void movePiece(Location from, Location to, Player* player);
    /*! \fn countPiecesFor
    *   \brief counts the number of pieces a player has on the board.
    *
    *   returns the number of pieces that a given player has on the board.
    *   used for example to display the number of pieces each player owns.
    *
    *   @param player   owner of the pieces we want ot count.
    */
    int countPiecesFor(Player* player) const;
    /*! \fn getPieceLocationsFor
    *   \brief get locatons of pieces for a given player.
    *
    *   returns a vector of Locations, of all pieces a given player has on the board.
    *   used for example when checking if a player is trying to move a piece.
    *
    *   @param player   owner of the pieces we want Location of.
    */
    std::vector<Location> getPieceLocationsFor(Player* player) const;
    /*! \fn retract
    *   \brief retracts one game move backwards.
    */
    void retract();

    /* \brief prints the board.
    *   
    *   @param os   output stream.
    *   @param rhs  Board to be printed.
    */
    friend std::ostream& operator<<(std::ostream& os, const Board& rhs);

protected:
    Piece*** pieces_; //!< pointer to a 2d array of Piece pointers, essentaly the board layout.
    int width_; //!< the widht of the board.
    int height_; //!< the height of the board.
    std::stack<Piece*> graveyard_; //!< stack of killed pieces, used when retracting and putting pieces back on the board
    std::stack<MoveHistoryState> moveHistory_; //!< move history, a history of all moves made, used when retracting
};

std::ostream& operator<<(std::ostream& os, const Board& rhs);

}

#endif