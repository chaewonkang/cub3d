/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:37:12 by seogkim           #+#    #+#             */
/*   Updated: 2020/11/07 20:12:38 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->move.forward = 1;
	if (keycode == S_KEY)
		data->move.backward = 1;
	if (keycode == A_KEY)
		data->move.left = 1;
	if (keycode == D_KEY)
		data->move.right = 1;
	if (keycode == LEFT_ARROW)
		data->turn.left = 1;
	if (keycode == RIGHT_ARROW)
		data->turn.right = 1;
	if (keycode == ESC)
		close_screen_mlx(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->move.forward = 0;
	if (keycode == S_KEY)
		data->move.backward = 0;
	if (keycode == A_KEY)
		data->move.left = 0;
	if (keycode == D_KEY)
		data->move.right = 0;
	if (keycode == LEFT_ARROW)
		data->turn.left = 0;
	if (keycode == RIGHT_ARROW)
		data->turn.right = 0;
	return (0);
}

int	close_window(t_data *data)
{
	close_screen_mlx(data);
	return (0);
}

int	handle_movement(t_data *data)
{
	if (data->move.forward == 1)
		move_forward(data);
	if (data->move.backward == 1)
		move_backward(data);
	if (data->move.left == 1)
		move_left(data);
	if (data->move.right == 1)
		move_right(data);
	if (data->turn.left == 1)
		turn_left(data);
	if (data->turn.right == 1)
		turn_right(data);
	if (data->move.forward == 1 || data->move.backward == 1 ||
		data->move.left == 1 || data->move.right == 1 ||
		data->turn.left == 1 || data->turn.right == 1)
	{
		data->move_counter++;
		render_screen(data);
	}
	return (0);
}
