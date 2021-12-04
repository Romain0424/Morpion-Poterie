/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "player_manager.h"
#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_PLAYER_MANAGER_MOCK

int i = 0;
int xs[] = {0,0,3,1,1,1,0,2,2,2,0,1};
int ys[] = {1,2,0,1,1,2,0,0,1,2,0,1};
PieceType Piece;

void PlayerManager_init (void)
{
    Piece = CIRCLE;
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    if(i%2 == 0){Piece = CIRCLE; printf("This is CIRCLE turn\n");}
    else{Piece = CROSS;printf("This is CROSS turn\n");}
    printf("%d , %d\n\n",xs[i],ys[i]);
    if(Board_putPiece(xs[i],ys[i],Piece) == SQUARE_IS_NOT_EMPTY){BoardView_sayCannotPutPiece();}
    i++;
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
