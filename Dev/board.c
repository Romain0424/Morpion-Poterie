#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tictactoe_errors.h"

EndOfGameCallback EndOfGameCallbackFunAdress;
SquareChangeCallback SquareChangeCallbackFunAdress;
PieceType board[3][3];

void checkRow(const PieceType boardSquares[3][3],GameResult * gameResult , Coordinate lastX, Coordinate lastY)
{
    if(boardSquares[lastY][lastX] == boardSquares[lastY][((int)lastX + 1) % 3] && boardSquares[lastY][lastX] == boardSquares[lastY][((int)lastX + 2) % 3])
    {
        switch(Board_getSquareContent(lastX, lastY))
        {
        case CIRCLE :
            * gameResult = CIRCLE_WINS;
            break;
        case CROSS :
            * gameResult = CROSS_WINS;
            break;
        case NONE :
            break;
        default :
            fatalError("An error happened during checkrow.");
        }
    }
}
void checkColumn(const PieceType boardSquares[3][3],GameResult * gameResult , Coordinate lastX, Coordinate lastY)
{
    if(boardSquares[lastY][lastX] == boardSquares[((int)lastY + 1) % 3][lastX] && boardSquares[lastY][lastX] == boardSquares[((int)lastY + 2) % 3][lastX])
    {
        switch(Board_getSquareContent(lastX, lastY))
        {
        case CIRCLE :
            * gameResult = CIRCLE_WINS;
            break;
        case CROSS :
            * gameResult = CROSS_WINS;
            break;
        case NONE :
            break;
        default :
            fatalError("An error happened during checkColumn.");
        }
    }
}

void checkUpperDiag(const PieceType boardSquares[3][3],GameResult *gameResult, Coordinate lastX, Coordinate lastY)
{
    if(boardSquares[lastY][lastX] == boardSquares[((((int)lastY - 1) % 3)+3)%3][(lastX + 1) % 3] && boardSquares[lastY][lastX] == boardSquares[((((int)lastY - 2) % 3)+3)%3][(lastX + 2) % 3])
    {
        switch(Board_getSquareContent(lastX, lastY))
        {
        case CIRCLE :
            * gameResult = CIRCLE_WINS;
            break;
        case CROSS :
            * gameResult = CROSS_WINS;
            break;
        case NONE :
            break;
        default :
            fatalError("An error happened during checkUpperDiag.");
        }
    }
}
void checkDownDiag(const PieceType boardSquares[3][3],GameResult *gameResult , Coordinate lastX, Coordinate lastY)
{
    if(boardSquares[lastY][lastX] == boardSquares[((int)lastY + 1) % 3][((int)lastX + 1) % 3] && boardSquares[(int)lastY][(int)lastX] == boardSquares[((int)lastY + 2) % 3][((int)lastX + 2) % 3] )
    {
        switch(Board_getSquareContent(lastX, lastY))
        {
        case CIRCLE :
            * gameResult = CIRCLE_WINS;
            break;
        case CROSS :
            * gameResult = CROSS_WINS;
            break;
        case NONE :
            break;
        default :
            fatalError("An error happened during checkDownDiag.");
        }
    }
}

static bool isBoardFull(const PieceType boardSquares[3][3])
{
	for(int y=0; y<3; y++)
	{
		for(int x=0; x<3; x++)
		{
			if(boardSquares[y][x] == NONE)
			{
				return false;
			}
		}
	}
	return true;
}

void copyCurrentBoard(const PieceType boardSquares[3][3])
{
	for(int j = 0;j<3; j++)
	{
		for(int i = 0; i<3; i++)
		{
			board[j][i] = boardSquares[i][j];
		}
	}
}

/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */
static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
    if(EndOfGameCallbackFunAdress == NULL)
    {
        *gameResult = DRAW;
        copyCurrentBoard(boardSquares);
    }


    checkRow(board, gameResult , lastChangeX , lastChangeY);
    checkColumn(board, gameResult , lastChangeX , lastChangeY);
    if((lastChangeX + lastChangeY) == 2)
    {
        checkUpperDiag(board, gameResult , lastChangeX , lastChangeY);
    }
    if(lastChangeX == lastChangeY)
    {
        checkDownDiag(board, gameResult , lastChangeX , lastChangeY);
    }

    if(* gameResult == CIRCLE_WINS)
    {
        if(EndOfGameCallbackFunAdress != NULL)
        {
            EndOfGameCallbackFunAdress((GameResult) CIRCLE_WINS);
        }
        return true;
    }
    else if(* gameResult == CROSS_WINS)
    {
        if(EndOfGameCallbackFunAdress != NULL)
        {
            EndOfGameCallbackFunAdress((GameResult) CROSS_WINS);
        }
		return true;
    }
    else if(isBoardFull(board) == true)
	{
        if(EndOfGameCallbackFunAdress != NULL)
        {
            EndOfGameCallbackFunAdress((GameResult) NONE);
        }
		return true;
	}
    else
    {
        return false;
    }
}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{
    for(int j = 0;j<3;j++)
    {
        for(int i = 0; i<3; i++)
        {
            board[j][i] = NONE;
        }
    }
    EndOfGameCallbackFunAdress = onEndOfGame; //store the EndOfGameCallback function address
    SquareChangeCallbackFunAdress = onSquareChange; //store the SquareChangeCallback function address

    SquareChangeCallbackFunAdress(0,0,NONE);
}

void Board_free ()
{
	for(int j = 0;j<3;j++)
	{
		for(int i = 0; i<3; i++)
		{
			board[j][i] = NONE;
		}
	}
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    GameResult  ResultOfGame = DRAW;
    if(x <= 2 && x >= 0 && y <= 2 && y >= 0 && kindOfPiece != NONE)
    {
        if(Board_getSquareContent(x,y) == NONE)
        {
            board[y][x] = kindOfPiece;

            SquareChangeCallbackFunAdress(x,y,kindOfPiece);
            isGameFinished(board, x, y, &ResultOfGame);
            return PIECE_IN_PLACE;
        }
    }
    return SQUARE_IS_NOT_EMPTY;
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
    switch(board[y][x]){
    case CIRCLE :
        return CIRCLE;
    case CROSS :
        return CROSS;
    case NONE:
        return NONE;
    default :
    	exit(-100);
    }
}
