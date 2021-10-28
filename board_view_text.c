#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
  // TODO: à compléter
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
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
