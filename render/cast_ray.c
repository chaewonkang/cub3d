/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:16:51 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_raycast_variables(t_data *data, int x)
{
	data->ray.camera_x = (2 * x / data->file.res.x) - 1;
	data->ray.ray_dir.x =
		data->ray.dir_vec.x + data->ray.camera_plane.x * data->ray.camera_x;
	data->ray.ray_dir.y =
		data->ray.dir_vec.y + data->ray.camera_plane.y * data->ray.camera_x;
	data->ray.box_map.x = (int)data->ray.player_pos.x;
	data->ray.box_map.y = (int)data->ray.player_pos.y;
	data->ray.delta_dist.x = fabs(1 / data->ray.ray_dir.x);
	data->ray.delta_dist.y = fabs(1 / data->ray.ray_dir.y);
}

static void	calculate_step_and_initial_side_dist(t_data *data)
{
	if (data->ray.ray_dir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.side_dist.x = (data->ray.player_pos.x - data->ray.box_map.x)
													* data->ray.delta_dist.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.side_dist.x = (data->ray.box_map.x + 1.0 -
							data->ray.player_pos.x) * data->ray.delta_dist.x;
	}
	if (data->ray.ray_dir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.side_dist.y = (data->ray.player_pos.y - data->ray.box_map.y)
													* data->ray.delta_dist.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.side_dist.y = (data->ray.box_map.y + 1.0 -
							data->ray.player_pos.y) * data->ray.delta_dist.y;
	}
}

static void	perform_dda(t_data *data)
{
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta_dist.x;
			data->ray.box_map.x += data->ray.step.x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta_dist.y;
			data->ray.box_map.y += data->ray.step.y;
			data->ray.side = 1;
		}
		if (data->file.map[data->ray.box_map.y][data->ray.box_map.x] == '1')
			data->ray.hit = 1;
	}
}

static void	correct_perp_wall_dist(t_data *data)
{
	if (data->ray.side == 0)
	{
		data->ray.perp_wall_dist =
		(data->ray.box_map.x - data->ray.player_pos.x +
		(1 - data->ray.step.x) / 2) / data->ray.ray_dir.x;
	}
	else
	{
		data->ray.perp_wall_dist =
		(data->ray.box_map.y - data->ray.player_pos.y +
		(1 - data->ray.step.y) / 2) / data->ray.ray_dir.y;
	}
}

void		cast_ray(t_data *data, int x)
{
	set_raycast_variables(data, x);
	calculate_step_and_initial_side_dist(data);
	perform_dda(data);
	correct_perp_wall_dist(data);
}
