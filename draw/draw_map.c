/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:42:16 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:42:35 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ceiling(t_data *data, int x)
{
	int	y;
	int	ceiling_color;

	y = 0;
	ceiling_color = get_color(data->file.ceiling_color);
	while (y < data->draw.start)
	{
		if (data->move_counter % 2 != 0)
			my_mlx_pixel_put(&data->mlx.first_img, x, y, ceiling_color);
		if (data->move_counter % 2 == 0)
			my_mlx_pixel_put(&data->mlx.second_img, x, y, ceiling_color);
		y++;
	}
}

void	draw_wall(t_data *data, int x)
{
	int	y;

	y = data->draw.start;
	while (y < data->draw.end)
	{
		if (data->ray.side == 1 && data->ray.ray_dir.y > 0)
			draw_south_texture_pixel(data, x, y);
		if (data->ray.side == 1 && data->ray.ray_dir.y < 0)
			draw_north_texture_pixel(data, x, y);
		if (data->ray.side == 0 && data->ray.ray_dir.x < 0)
			draw_west_texture_pixel(data, x, y);
		if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
			draw_east_texture_pixel(data, x, y);
		y++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int	y;
	int	floor_color;

	y = data->draw.end;
	floor_color = get_color(data->file.floor_color);
	while (y < data->file.res.y)
	{
		if (data->move_counter % 2 != 0)
			my_mlx_pixel_put(&data->mlx.first_img, x, y, floor_color);
		if (data->move_counter % 2 == 0)
			my_mlx_pixel_put(&data->mlx.second_img, x, y, floor_color);
		y++;
	}
}
