/**
 * @file board.h
 *
 * This module handles the logic of the board of the tic tac toe game
 *
 * @date 6/10/2016
 * @author Jonathan ILIAS-PILLET & Richard WOODWARD
 */

#if !defined BOARD_H_
#define BOARD_H_

#include <stdbool.h>

/**
 * A logic coordinate in the board. This can be
 * used to handle a row or a column number starting at 0.
 *
 * Values must be between 0 and 2 included.
 */
typedef unsigned int Coordinate;

/**
 * A kind of piece.
 *
 * Note that this type has a special "void" value called NONE.
 */
typedef enum
{
	NONE,   /**< used to tell there is no piece (a piece that has no kind is not a piece) */
	CROSS,  /**< a cross ("X") piece */
	CIRCLE  /**< a circle ("O") piece */
} PieceType;

/**
 * Result of a piece put action (@see #Board_putPiece)
 */
typedef enum
{
	PIECE_IN_PLACE,       /**< no problem: the piece has been put in the specified square */
	SQUARE_IS_NOT_EMPTY   /**< the specified square is not empty, then the piece has not been put */
} PutPieceResult;

/**
 * Winning status after the game has ended.
 */
typedef enum
{
	DRAW,        /**< draw game, not player wins */
	CROSS_WINS,  /**< crosses player wins */
	CIRCLE_WINS  /**< circles player wins */
} GameResult;

/**
 * Pointer of a function that can be called when a square changes.
 *
 * @param [in] x the board's column where the square is
 * @param [in] y the board's row where the square is
 * @param [in] newContent the new square's content
 */
typedef void (*SquareChangeCallback) (Coordinate x, Coordinate y, PieceType newContent);

/**
 * Pointer of a function that can be called when the game ends.
 *
 * @param [in] result result of the game (who wins or not)
 */
typedef void (*EndOfGameCallback) (GameResult result);

/**
 * The board's constructor.
 *
 * @param [in] onSquareChange address of the function that will be called each time
 * a square changes (can be NULL if unused)
 * @param [in] onEndOfGame address of the function that will be called when the end
 * of game happens
 */
extern void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame);

/**
 * The board's destructor.
 *
 * @pre the board must have been constructed
 */
extern void Board_free ();

/**
 * Requests a piece placement into a specified square.
 *
 * @param [in] x logical column coordinate
 * @param [in] y logical row coordinate
 * @param [in] kindOfPiece type of the piece (CROSS or CIRCLE)
 *
 * @pre kindOfPiece must not be "NONE"
 * @pre x must be in [0..2]
 * @pre y must be in [0..2]
 *
 * @retval PIECE_IN_PLACE the piece has been put in the square
 * @retval SQUARE_IS_NOT_EMPTY the piece cannot be put in the square as there is already one
 */
extern PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece);

/**
 * Gives the content of a square
 *
 * @param [in] x logical column coordinate
 * @param [in] y logical row coordinate
 *
 * @pre x must be in [0..2]
 * @pre y must be in [0..2]
 *
 * @return the square's content (NONE if it's empty)
 */
extern PieceType Board_getSquareContent (Coordinate x, Coordinate y);


#endif /* !defined BOARD_H_ */
