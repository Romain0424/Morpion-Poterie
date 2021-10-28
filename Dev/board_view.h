/**
 * @file board_view.h
 *
 * Tic tac toe's board visualisation module
 *
 * @date 7/10/2016
 * @author Jonathan ILIAS-PILLET & Richard WOODWARD
 */

#if !defined BOARD_VIEW_H_
#define BOARD_VIEW_H_

#include "board.h"

/**
 * Constructor of the board view.
 *
 * Must be called before any other function of this module.
 */
extern void BoardView_init (void);

/**
 * Destructor of the board view.
 *
 * Must be called after using any function of this module to free
 * related resources.
 */
extern void BoardView_free (void);

/**
 * Displays the entire board (including background) at current status.
 */
extern void BoardView_displayAll (void);

/**
 * Display the specified content into the specified square.
 *
 * @param [in] x logical column coordinate
 * @param [in] y logical row coordinate
 * @param [in] kindOfPiece the content to display (can be NONE if empty)
 *
 * @pre x must be in [0..2]
 * @pre y must be in [0..2]
 */
extern void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece);

/**
 * Displays a message to the user at the end of the game.
 *
 * @param [in] result winning status
 */
extern void BoardView_displayEndOfGame (GameResult result);

/**
 * Displays who has to play.
 *
 * @param [in] thisPlayer the player who has to play, designated by its piece type
 *
 * @pre thisPlayer cannot be NONE
 */
extern void BoardView_displayPlayersTurn (PieceType thisPlayer);

/**
 * Displays a message when a move has been refused because the square is not empty
 */
extern void BoardView_sayCannotPutPiece (void);

#endif /* !defined BOARD_VIEW_H_ */
