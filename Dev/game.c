/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */
#include <stdio.h>
#include <stdlib.h>
#include "tictactoe_errors.h"
#include "player_manager.h"
#include "board_view.h"
#include "board.h"

void circleWinFunCall()
{
	printf("Circle win !\n");
	//TODO functions to call in case circle wins
}

void crossWinFunCall()
{
	printf("Cross win !\n");
	//TODO functions to call in case cross wins
}

void drawFunCall()
{
	printf("Game ended in a draw.\n");
	//TODO functions to call in case of a draw
}

void EndOfGameCallBackFunction(GameResult result)
{
	switch(result)
	{
	case 2: circleWinFunCall();break;
	case 1: crossWinFunCall();break;
	case 0: drawFunCall();break;
	default : fatalError("le gagnant n'est pas défini.\n");break;
	}

	Board_free();
}

void SquareChangeCallBackFunction(Coordinate x, Coordinate y, PieceType newContent)
{
    BoardView_displaySquare(x,y,newContent);
    //affichage
}


void Game_init (void)
{
	//TODO call l'init dans le module de view après l'init du module de board.

    void (*OnSquareChangeCallBack) = &SquareChangeCallBackFunction;
    void (*OnEndOfGameCallBack) = &EndOfGameCallBackFunction;

    Board_init(OnSquareChangeCallBack, OnEndOfGameCallBack);


}

void Game_free (void)
{
    // TODO: libérer tous les modules
	// j'imagine qu'il faut delete le board et les références aux fonction ? //TODO delete the comment
}

void Game_loop (void)
{
	bool TemoinFinPartie = false;
    BoardView_init();
	Board_putPiece(0,0,CIRCLE);
	Board_putPiece(0,1,CIRCLE);
	Board_putPiece(0,2,CIRCLE);

	/*while(TemoinFinPartie = false){
		Board_putPiece(0, 1, CROSS);

	// TODO: à compléter
	}*/
}
