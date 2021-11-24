/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"

SquareChangeCallback SquareChangeCallBackFunction(Coordinate x, Coordinate y, PieceType newContent){
    //affichage
}

EndOfGameCallback EndOfGameCallBackFunction(GameResult * Result){
    //result
}
void Game_init (void)
{
    SquareChangeCallback (*OnSquareChangeCallBack)(Coordinate, Coordinate, PieceType);
    OnSquareChangeCallBack = &SquareChangeCallBackFunction;

    EndOfGameCallback (*OnEndOfGameCallBack)(GameResult *);
    OnEndOfGameCallBack = &EndOfGameCallBackFunction;

    Board_init(OnSquareChangeCallBack, OnEndOfGameCallBack);
    //EndOfGameCallback onEndOfGame = ;
    //Board_init(onSquareChangeCallBack, onEndOffGame);
}

void Game_free (void)
{
  // TODO: libérer tous les modules
}

void Game_loop (void)
{
    /*Board_init();
    Board_putPiece(1,2,CIRCLE);*/

    Board_putPiece(0,0,CIRCLE);
    Board_putPiece(1,1,CIRCLE);
    Board_putPiece(2,2,CIRCLE);
	// TODO: à compléter
}
