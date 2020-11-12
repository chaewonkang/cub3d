/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:15:56 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_data *data)
{
	double	movespeed;
	int		new_y;
	int		new_x;

	movespeed = 0.06;
	new_y = data->ray.player_pos.y + data->ray.dir_vec.y * movespeed;
	new_x = data->ray.player_pos.x + data->ray.dir_vec.x * movespeed;
	if (data->file.map[new_y][(int)data->ray.player_pos.x] != '1' &&
			data->file.map[new_y][(int)data->ray.player_pos.x] != '2')
		data->ray.player_pos.y += data->ray.dir_vec.y * movespeed;
	if (data->file.map[(int)data->ray.player_pos.y][new_x] != '1' &&
			data->file.map[(int)data->ray.player_pos.y][new_x] != '2')
		data->ray.player_pos.x += data->ray.dir_vec.x * movespeed;
}

void	move_backward(t_data *data)
{
	double	movespeed;
	int		new_y;
	int		new_x;

	movespeed = 0.06;
	new_y = data->ray.player_pos.y - data->ray.dir_vec.y * movespeed;
	new_x = data->ray.player_pos.x - data->ray.dir_vec.x * movespeed;
	if (data->file.map[new_y][(int)data->ray.player_pos.x] != '1' &&
			data->file.map[new_y][(int)data->ray.player_pos.x] != '2')
		data->ray.player_pos.y -= data->ray.dir_vec.y * movespeed;
	if (data->file.map[(int)data->ray.player_pos.y][new_x] != '1' &&
			data->file.map[(int)data->ray.player_pos.y][new_x] != '2')
		data->ray.player_pos.x -= data->ray.dir_vec.x * movespeed;
}

void	move_left(t_data *data)
{
	double	movespeed;
	int		new_y;
	int		new_x;

	movespeed = 0.06;
	new_y = data->ray.player_pos.y - data->ray.camera_plane.y * movespeed;
	new_x = data->ray.player_pos.x - data->ray.camera_plane.x * movespeed;
	if (data->file.map[new_y][(int)data->ray.player_pos.x] != '1' &&
			data->file.map[new_y][(int)data->ray.player_pos.x] != '2')
		data->ray.player_pos.y -= data->ray.camera_plane.y * movespeed;
	if (data->file.map[(int)data->ray.player_pos.y][new_x] != '1' &&
			data->file.map[(int)data->ray.player_pos.y][new_x] != '2')
		data->ray.player_pos.x -= data->ray.camera_plane.x * movespeed;
}

void	move_right(t_data *data)
{
	double	movespeed;
	int		new_y;
	int		new_x;

	movespeed = 0.06;
	new_y = data->ray.player_pos.y + data->ray.camera_plane.y * movespeed;
	new_x = data->ray.player_pos.x + data->ray.camera_plane.x * movespeed;
	if (data->file.map[new_y][(int)data->ray.player_pos.x] != '1' &&
			data->file.map[new_y][(int)data->ray.player_pos.x] != '2')
		data->ray.player_pos.y += data->ray.camera_plane.y * movespeed;
	if (data->file.map[(int)data->ray.player_pos.y][new_x] != '1' &&
			data->file.map[(int)data->ray.player_pos.y][new_x] != '2')
		data->ray.player_pos.x += data->ray.camera_plane.x * movespeed;
}
