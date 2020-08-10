/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:42:21 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:42:47 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_north_texture_pixel(t_data *data, int x, int y)
{
	int	pixel;

	data->north.tex.y = (int)data->north.tex_pos & (data->north.img_width - 1);
	data->north.tex_pos += data->north.step;
	pixel = ((data->north.tex.y * data->north.img.line_len) +
					data->north.tex.x * (data->north.img.bits_per_pixel / 8));
	data->north.color = *(unsigned int *)(data->north.img.addr + pixel);
	if (data->ray.side == 1)
		data->north.color = (data->north.color >> 1) & 8355711;
	if (data->move_counter % 2 != 0)
		my_mlx_pixel_put(&data->mlx.first_img, x, y, data->north.color);
	if (data->move_counter % 2 == 0)
		my_mlx_pixel_put(&data->mlx.second_img, x, y, data->north.color);
}

void	draw_south_texture_pixel(t_data *data, int x, int y)
{
	int	pixel;

	data->south.tex.y = (int)data->south.tex_pos & (data->south.img_width - 1);
	data->south.tex_pos += data->south.step;
	pixel = ((data->south.tex.y * data->south.img.line_len) +
					data->south.tex.x * (data->south.img.bits_per_pixel / 8));
	data->south.color = *(unsigned int *)(data->south.img.addr + pixel);
	if (data->ray.side == 1)
		data->south.color = (data->south.color >> 1) & 8355711;
	if (data->move_counter % 2 != 0)
		my_mlx_pixel_put(&data->mlx.first_img, x, y, data->south.color);
	if (data->move_counter % 2 == 0)
		my_mlx_pixel_put(&data->mlx.second_img, x, y, data->south.color);
}

void	draw_west_texture_pixel(t_data *data, int x, int y)
{
	int	pixel;

	data->west.tex.y = (int)data->west.tex_pos & (data->west.img_width - 1);
	data->west.tex_pos += data->west.step;
	pixel = ((data->west.tex.y * data->west.img.line_len) +
					data->west.tex.x * (data->west.img.bits_per_pixel / 8));
	data->west.color = *(unsigned int *)(data->west.img.addr + pixel);
	if (data->ray.side == 1)
		data->west.color = (data->west.color >> 1) & 8355711;
	if (data->move_counter % 2 != 0)
		my_mlx_pixel_put(&data->mlx.first_img, x, y, data->west.color);
	if (data->move_counter % 2 == 0)
		my_mlx_pixel_put(&data->mlx.second_img, x, y, data->west.color);
}

void	draw_east_texture_pixel(t_data *data, int x, int y)
{
	int	pixel;

	data->east.tex.y = (int)data->east.tex_pos & (data->east.img_width - 1);
	data->east.tex_pos += data->east.step;
	pixel = ((data->east.tex.y * data->east.img.line_len) +
					data->east.tex.x * (data->east.img.bits_per_pixel / 8));
	data->east.color = *(unsigned int *)(data->east.img.addr + pixel);
	if (data->ray.side == 1)
		data->east.color = (data->east.color >> 1) & 8355711;
	if (data->move_counter % 2 != 0)
		my_mlx_pixel_put(&data->mlx.first_img, x, y, data->east.color);
	if (data->move_counter % 2 == 0)
		my_mlx_pixel_put(&data->mlx.second_img, x, y, data->east.color);
}
