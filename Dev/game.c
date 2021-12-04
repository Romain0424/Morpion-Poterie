/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */
#include "player_manager.h"
#include "board_view.h"
#include "board.h"

bool temoinFinPartie = false;

void EndOfGameCallBackFunction(GameResult result)
{
    temoinFinPartie = true;
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

    BoardView_init();
    void (*OnSquareChangeCallBack) = &SquareChangeCallBackFunction;
    void (*OnEndOfGameCallBack) = &EndOfGameCallBackFunction;

    Board_init(OnSquareChangeCallBack, OnEndOfGameCallBack);


}

void Game_free (void)
{
}

void Game_loop (void)
{
    PlayerManager_init();
    while(temoinFinPartie == false)
    {
        PlayerManager_oneTurn();
    }
}
