/**
 * @file tictactoe_erros.c
 *
 * @date 8 oct. 2016
 * @author jilias
 */

#include "tictactoe_errors.h"
#include <stdio.h>
#include <stdlib.h>

void fatalError (const char *message)
{
	fprintf (stderr, "%s\n", message);
	exit (1);
}
