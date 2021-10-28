/**
 * @file player_mock.h
 *
 * Players interaction's manager module
 *
 * @date 7/10/2016
 * @author Jonathan ILIAS-PILLET & Richard WOODWARD
 */

#if !defined PLAYER_MANAGER_H_
#define PLAYER_MANAGER_H_

/**
 * Constructor of player manager.
 */
extern void PlayerManager_init (void);

/**
 * Destructor of player manager.
 */
extern void PlayerManager_free (void);

/**
 * Waits for one player move and do subsequent actions.
 *
 * This function does not return until the player has made a
 * valid move.
 */
extern void PlayerManager_oneTurn (void);

#endif /* !defined PLAYER_MANAGER_H_ */
