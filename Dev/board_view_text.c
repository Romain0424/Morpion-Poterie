#include "board_view.h"
#include <stdio.h>
#include <stdlib.h>
#include "tictactoe_errors.h"

#if defined CONFIG_TEXTUI

PieceType ViewBoard[3][3];

void BoardView_init (void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ViewBoard[j][i] = NONE;
        }
    }
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
    printf("  A   B   C  \n");
    for(int j = 0; j < 3; j++)
    {
        printf("%d ",j);
        for(int i = 0; i < 3; i++)
        {
            switch(ViewBoard[j][i])
            {
                case NONE: printf(" "); break;
                case CIRCLE: printf("O"); break;
                case CROSS: printf("X"); break;
            }
            if(i<2){printf(" | ");}
        }
        printf("\n");
        if(j<2){printf("  -----------\n");}
    }
    printf("\n\n");
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    ViewBoard[y][x] = kindOfPiece;
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
    switch (result)
    {
        case 0 : printf("The game ended in a draw.");break;
        case 1 : printf("Crooses won !");break;
        case 2 : printf("Circles won !");break;
        default :
            fatalError("The end of game winner is not properly defined.");
    }
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
    if(thisPlayer == 2){printf("This is CIRCLE turn\n");}
    else if (thisPlayer == 1){printf("This is CROSS turn\n");}
    else{fatalError("The asked piece is not recognised.");}
}

void BoardView_sayCannotPutPiece (void)
{
  printf("Sorry but the piece placement is not allowed in that case\n");
}

#endif // defined CONFIG_TEXTUI
