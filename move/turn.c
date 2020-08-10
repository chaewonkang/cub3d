/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:37:59 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:38:01 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	turn_left(t_data *data)
{
	double	rotspeed;
	double	old_dir_vec_x;
	double	old_camera_plane_x;

	rotspeed = 0.03;
	old_dir_vec_x = data->ray.dir_vec.x;
	old_camera_plane_x = data->ray.camera_plane.x;
	data->ray.dir_vec.x = data->ray.dir_vec.x * cos(-rotspeed) -
						data->ray.dir_vec.y * sin(-rotspeed);
	data->ray.dir_vec.y = old_dir_vec_x * sin(-rotspeed) +
						data->ray.dir_vec.y * cos(-rotspeed);
	data->ray.camera_plane.x = data->ray.camera_plane.x * cos(-rotspeed) -
							data->ray.camera_plane.y * sin(-rotspeed);
	data->ray.camera_plane.y = old_camera_plane_x * sin(-rotspeed) +
							data->ray.camera_plane.y * cos(-rotspeed);
}

void	turn_right(t_data *data)
{
	double	rotspeed;
	double	old_dir_vec_x;
	double	old_camera_plane_x;

	rotspeed = 0.03;
	old_dir_vec_x = data->ray.dir_vec.x;
	old_camera_plane_x = data->ray.camera_plane.x;
	data->ray.dir_vec.x = data->ray.dir_vec.x * cos(rotspeed) -
						data->ray.dir_vec.y * sin(rotspeed);
	data->ray.dir_vec.y = old_dir_vec_x * sin(rotspeed) +
						data->ray.dir_vec.y * cos(rotspeed);
	data->ray.camera_plane.x = data->ray.camera_plane.x * cos(rotspeed) -
							data->ray.camera_plane.y * sin(rotspeed);
	data->ray.camera_plane.y = old_camera_plane_x * sin(rotspeed) +
							data->ray.camera_plane.y * cos(rotspeed);
}
