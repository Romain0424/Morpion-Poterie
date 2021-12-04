/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */
#include "player_manager.h"
#include "board.h"
#include "board_view.h"
#include <stdio.h>
#include <stdlib.h>

#if defined CONFIG_PLAYER_MANAGER_SCANF
int i = 0;
PieceType Piece = 2;


PieceType changePiece(){
    Piece = (Piece%2)+1; // Allows one to change the piece Type from CIRCLE to CROSS and vice versa excluding the NONE
    return Piece;
}

int * getpositions()
{
    int num1;
    int num2;
    char term;
    static int a[2];
    if(scanf("%d,%d%c", &num1, &num2, &term) != 3 || term != '\n')
    {
        fflush(stdin);
        printf("failure\n");
        a[0] = -1;
        a[1] = -1;
        return a;
    }
    else
    {
        printf("valid integer followed by enter key\n");
    }
    a[0] = num1;
    a[1] = num2;
    return a;
}

void PlayerManager_init (void)
{
    Piece = CIRCLE;
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
    BoardView_displayPlayersTurn(Piece);
    printf("Please enter the wanted coordinates as a X,Y format :");
    int * pos;
    pos = getpositions();
    if(Board_putPiece(pos[0],pos[1],Piece) == SQUARE_IS_NOT_EMPTY){BoardView_sayCannotPutPiece();BoardView_displayAll();}
    else{Piece = changePiece();}
    i++;
}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
