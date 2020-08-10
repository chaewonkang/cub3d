/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:35:38 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:35:39 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H
# include "cub3d.h"

/*
** ERROR MESSAGES
*/

# define INVALID_ARGUMENT_AMOUNT 1
# define INVALID_FILE_FORMAT 2
# define INVALID_ARGUMENT 3
# define INVALID_FD 4
# define INVALID_LINE 5
# define INVALID_TOTAL_ELEMENT_AMOUNT 6
# define MALLOC_FAIL 7
# define INVALID_ELEMENT_FORMAT 8
# define INVALID_RESOLUTION 9
# define INVALID_NORTH_PTT 10
# define INVALID_SOUTH_PTT 11
# define INVALID_WEST_PTT 12
# define INVALID_EAST_PTT 13
# define INVALID_SPRITE_PTT 14
# define INVALID_FLOOR_COLOR 15
# define INVALID_CEILING_COLOR 16
# define INVALID_MAP 17
# define INVALID_IMAGE 18
# define INVALID_IMAGE_ADDRESS 19
# define INVALID_FD_OPEN 20
# define INVALID_WRITE 21
# define INVALID_PLAYER_AMOUNT 22
# define INVALID_SCREENSHOT_SIZE 23
# define INVALID_CHARACTER 24

/*
** ID ELEMENTS FOR PARSING
*/

# define ERROR -1
# define RESOLUTION 0
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define SPRITE 5
# define FLOOR 6
# define CEILING 7
# define MAP 8
# define EMPTY_LINE 9

/*
** X11 EVENTS
*/

# define KEY_PRESS 2
# define KEY_RELEASE 3

/*
** KEYCODES
*/

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC 53

#endif
