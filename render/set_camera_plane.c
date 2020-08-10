/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:39:31 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:39:33 by seogkim          ###   ########.fr       */
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
