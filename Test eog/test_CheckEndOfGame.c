/**
 * @file test_checkEndOfGame.c
 *
 * End of game check function test suite
 *
 * @date 27 oct. 2016
 * @author Jonathan ILIAS-PILLET
 */

// WARNING : ".c" file inclusion only allowed for unit tests !
#include "board.c"
#include "test_CheckEndOfGame.h"
#include <stdio.h>

typedef struct
{
	PieceType board[3][3];
	Coordinate lastPutX;
	Coordinate lastPutY;
	bool expectedEndOfGameResult;
	GameResult expectedGameResult;
} BoardDataTest;

static const BoardDataTest DataTest[] =
{
{
{
{NONE, NONE, NONE},
{NONE, NONE, NONE},
{NONE, NONE, NONE}}, 0, 0, false, DRAW},
{
{
{NONE, NONE, NONE},
{NONE, CROSS, NONE},
{NONE, NONE, NONE}}, 0, 0, false, DRAW},
{
{
{NONE, NONE, NONE},
{NONE, CIRCLE, NONE},
{NONE, NONE, NONE}}, 1, 1, false, DRAW},
{
{
{CROSS, NONE, NONE},
{CROSS, CIRCLE, NONE},
{NONE, NONE, NONE}}, 0, 1, false, DRAW},
{
{
{CROSS, NONE, NONE},
{CROSS, CIRCLE, CIRCLE},
{NONE, CROSS, NONE}}, 1, 2, false, DRAW},
{
{
{CROSS, NONE, NONE},
{CIRCLE, CIRCLE, NONE},
{NONE, NONE, CROSS}}, 2, 2, false, DRAW},
{
{
{CROSS, NONE, NONE},
{CROSS, CIRCLE, CIRCLE},
{CROSS, NONE, NONE}}, 0, 1, true, CROSS_WINS},
{
{
{CROSS, NONE, NONE},
{CIRCLE, CIRCLE, CIRCLE},
{CROSS, NONE, NONE}}, 2, 1, true, CIRCLE_WINS},
{
{
{CROSS, NONE, NONE},
{CIRCLE, CROSS, CIRCLE},
{NONE, NONE, CROSS}}, 0, 0, true, CROSS_WINS},
{
{
{CROSS, NONE, CIRCLE},
{CROSS, CIRCLE, NONE},
{CIRCLE, NONE, CROSS}}, 1, 1, true, CIRCLE_WINS},
{
{
{CIRCLE, CROSS, CIRCLE},
{CIRCLE, CROSS, CIRCLE},
{CROSS, CIRCLE, CROSS}}, 2, 0, true, DRAW}

};

void testCheckEndOfGame (void)
{
	int successCount = 0;
	int failCount = 0;

	GameResult gameResult;
	bool end;

	for (int i = 0; i < (sizeof(DataTest) / sizeof(BoardDataTest)); i++)
	{
		end = isGameFinished (DataTest[i].board, DataTest[i].lastPutX, DataTest[i].lastPutY, &gameResult);
		if (end != DataTest[i].expectedEndOfGameResult)
		{
			printf ("test #%d failed, expected end of game was %s\n", i,
					DataTest[i].expectedEndOfGameResult ? "true" : "false");
			failCount++;
		}
		else
		{
			successCount++;
		}
		if (end)
		{
			if (gameResult != DataTest[i].expectedGameResult)
			{
				printf ("test #%d failed, expected result of game was %s\n",	i,
						DataTest[i].expectedGameResult == CROSS_WINS ?
								"CROSS_WINS" :
						DataTest[i].expectedGameResult == CIRCLE_WINS ?
								"CIRCLE_WINS" : "DRAW");
				failCount++;
			}
			else
			{
				successCount++;
			}
		}
	}

	printf ("*********\n%d of %d test cases succeeded\n",
			successCount, successCount + failCount);
}
