/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:15:59 by ckang            ###   ########.fr       */
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
