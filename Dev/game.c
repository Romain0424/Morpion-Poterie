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

bool TemoinFinPartie = false;

void EndOfGameCallBackFunction(GameResult result)
{
    TemoinFinPartie = true;
	BoardView_displayEndOfGame(result);
	Board_free();
    BoardView_free();
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
    BoardView_init();
    PlayerManager_init();
    while(TemoinFinPartie == false)
    {
        PlayerManager_oneTurn();
    }
}
