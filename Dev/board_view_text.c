#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//TODO find a way to delete this line with a CONFIG file with Cmake or something else.
#define CONFIG_TEXTUI

#if defined CONFIG_TEXTUI

PieceType ViewBoard[3][3];

void BoardView_init (void)
{
    //TODO à merger avec la fonction en dessous
    printf("  A   B   C  \n");
    for(int i = 0; i < 3; i++)
    {
        printf("%d ",i);
        for(int j = 0; j < 3; j++)
        {
            ViewBoard[j][i] = NONE;
            switch(board[j][i])
            {
                case NONE: printf(" "); break;
                case CIRCLE: printf("O"); break;
                case CROSS: printf("X"); break;
            }
            if(j<2){printf(" | ");}
        }
        printf("\n");
        if(i<2){printf("  -----------\n");}
    }
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
    printf("  A   B   C  \n");
    for(int i = 0; i < 3; i++)
    {
        printf("%d ",i);
        for(int j = 0; j < 3; j++)
        {
            switch(board[j][i])
            {
                case NONE: printf(" "); break;
                case CIRCLE: printf("O"); break;
                case CROSS: printf("X"); break;
            }
            if(j<2){printf(" | ");}
        }
        printf("\n");
        if(i<2){printf("  -----------\n");}
    }
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
    ViewBoard[y][x] = kindOfPiece; //TODO il doit y avoir un problème ici à checker
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
  // TODO: à compléter
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
  // TODO: à compléter
}

void BoardView_sayCannotPutPiece (void)
{
  // TODO: à compléter
}

#endif // defined CONFIG_TEXTUI
