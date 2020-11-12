/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:17:05 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_camera_plane(t_data *data)
{
	char	c;

	c =
	data->file.map[(int)data->ray.player_pos.y][(int)data->ray.player_pos.x];
	if (c == 'N')
	{
		data->ray.camera_plane.x = 0.66;
		data->ray.camera_plane.y = 0.0;
	}
	if (c == 'S')
	{
		data->ray.camera_plane.x = -0.66;
		data->ray.camera_plane.y = 0.0;
	}
	if (c == 'E')
	{
		data->ray.camera_plane.x = 0.0;
		data->ray.camera_plane.y = 0.66;
	}
	if (c == 'W')
	{
		data->ray.camera_plane.x = 0.0;
		data->ray.camera_plane.y = -0.66;
	}
}
