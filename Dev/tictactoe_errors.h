/**
 * @file tictactoe_errors.h
 *
 * Tic tac toe error management module
 *
 * @date 8/10/2016
 * @author Jonathan ILIAS-PILLET & Richard WOODWARD
 */

#if !defined TICTACTOE_ERRORS_H_
#define TICTACTOE_ERRORS_H_

/**
 * Call this when an unrecoverable error occurs.
 *
 * It displays a message and exits the program
 */
extern void fatalError (const char *message);

#endif /* !defined TICTACTOE_ERRORS_H_ */
