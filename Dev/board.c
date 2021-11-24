#include "board.h"
#include <assert.h>
#include<stdio.h>
#include<stdlib.h>

void checkRow(PieceType boardSquares[3][3],GameResult * gameResult , Coordinate lastX, Coordinate lastY)
{
    if(boardSquares[lastX][lastY] == boardSquares[lastX][(lastY + 1) % 3] && boardSquares[lastX][lastY] == boardSquares[lastX][(lastY + 2) % 3]){
        switch(Board_getSquareContent(lastX, lastY)){
        case CIRCLE :
            * gameResult = CIRCLE_WINS;
            break;
        case CROSS :
            * gameResult = CROSS_WINS;
            break;
        case NONE :
            exit(-100);   //This case should happen only if a mistake in the code has been done.
            break;
        }
    }
}
void checkColumn(PieceType boardSquares[3][3],GameResult * gameResult , Coordinate lastX, Coordinate lastY)
{
    if(boardSquares[lastX][lastY] == boardSquares[(lastX + 1) % 3][lastY] && boardSquares[lastX][lastY] == boardSquares[(lastX + 2) % 3][lastY]){
        switch(Board_getSquareContent(lastX, lastY)){
        case CIRCLE :
            * gameResult = CIRCLE_WINS;
            break;
        case CROSS :
            * gameResult = CROSS_WINS;
            break;
        case NONE :
            exit(-101);   //This case should happen only if a mistake in the code has been done.
            break;
        }
    }
}

void checkUpperDiag(PieceType boardSquares[3][3],GameResult *gameResult, Coordinate lastX, Coordinate lastY)
{
    if(boardSquares[lastX][lastY] == boardSquares[(lastX + 1) % 3][(lastY - 1) % 3] && boardSquares[lastX][lastY] == boardSquares[(lastX + 2) % 3][(lastY - 2) % 3]){
        switch(Board_getSquareContent(lastX, lastY)){
        case CIRCLE :
            * gameResult = CIRCLE_WINS;
            break;
        case CROSS :
            * gameResult = CROSS_WINS;
            break;
        case NONE :
            exit(-101);   //This case should happen only if a mistake in the code has been done.
            break;
        }
    }
}
void checkDownDiag(PieceType boardSquares[3][3],GameResult *gameResult , Coordinate lastX, Coordinate lastY)
{
    if(boardSquares[lastX][lastY] == boardSquares[(lastX + 1) % 3][(lastY + 1) % 3] && boardSquares[lastX][lastY] == boardSquares[(lastX + 2) % 3][(lastY + 2) % 3] ){
        switch(Board_getSquareContent(lastX, lastY)){
        case CIRCLE :
            printf("\n les cerlces gagnent");
            * gameResult = CIRCLE_WINS;
            break;
        case CROSS :
            * gameResult = CROSS_WINS;
            break;
        case NONE :
            exit(-101);   //This case should happen only if a mistake in the code has been done.
            break;
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
static bool isGameFinished (PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
    printf("is game finished 1");
    //boardSquares[2][0] = CIRCLE;
    //boardSquares[1][1] = CIRCLE;
    //boardSquares[0][2] = CIRCLE;
    checkRow(boardSquares, gameResult , lastChangeX , lastChangeY);
    checkColumn(boardSquares, gameResult , lastChangeX , lastChangeY);
    if((lastChangeX + lastChangeY) == 2){
        checkUpperDiag(boardSquares, gameResult , lastChangeX , lastChangeY);
    }
    if(lastChangeX == lastChangeY){
        checkDownDiag(boardSquares, gameResult , lastChangeX , lastChangeY);
    }
    printf("is game finished 2");
    if(* gameResult == CIRCLE_WINS){
        printf("\n\ncercle gagne !");
    }
    else {
        printf("pas gagne");
    }

}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            board[i][j] = NONE;
        }
    }
    onSquareChange(2,2,NONE);
    onEndOfGame(DRAW);
}

void Board_free ()
{
 //TO DO
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    GameResult  ResultOfGame = DRAW;
    if(x <= 2 && x >= 0 && y <= 2 && y >= 0 && kindOfPiece != NONE){
        if(Board_getSquareContent(x,y) == NONE){
            board[x][y] = kindOfPiece;
<<<<<<< HEAD
            /*isGameFinished(board, x , y, )*/
        }
        else{
            printf("This case is not empty");
=======
            printf("piece placed");
            isGameFinished(board, x, y, &ResultOfGame);
            return PIECE_IN_PLACE;
>>>>>>> Romain
        }
    }
    return SQUARE_IS_NOT_EMPTY;
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
    switch(board[x][y]){
    case CIRCLE :
        return CIRCLE;
        break;
    case CROSS :
        return CROSS;
        break;
    case NONE :
        return NONE;
        break;
    }
}
