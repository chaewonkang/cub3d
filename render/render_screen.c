/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:39:27 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:39:28 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_screen(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->file.res.x)
	{
		cast_ray(data, x);
		draw_vertical_line(data, x);
		data->zbuffer[x] = data->ray.perp_wall_dist;
		x++;
	}
	if (data->amount_of_sprites > 0)
		handle_sprites(data);
	if (data->file.save_to_bmp != 1)
	{
		if (data->move_counter % 2 != 0)
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
									data->mlx.first_img.img, 0, 0);
		if (data->move_counter % 2 == 0)
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
									data->mlx.second_img.img, 0, 0);
	}
}
