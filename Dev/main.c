/**
 * @file main.c
 *
 * @date 7/10/2016
 * @author Jonathan ILIAS-PILLET & Richard WOODWARD
 */

#include "game.h"

int main (void)
{
    Game_init ();

	Game_loop ();

	Game_free ();
	return 0;
}
