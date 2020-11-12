/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:42:19 by seogkim           #+#    #+#             */
/*   Updated: 2020/11/07 20:11:57 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_tex_x(t_data *data, int stripe)
{
	data->sprite_calc.tex.x = (int)(256 * (stripe -
								(-data->sprite_calc.sprite_width / 2 +
								data->sprite_calc.sprite_screen_x)) * 64 /
								data->sprite_calc.sprite_width) / 256;
}

static void	draw_sprite_pixel(t_data *data, int x, int y)
{
	int	d;
	int	pixel;
	int	color;

	d = y * 256 - data->file.res.y * 128 +
		data->sprite_calc.sprite_height * 128;
	data->sprite_calc.tex.y = ((d * data->sprite.img_width) /
									data->sprite_calc.sprite_height) / 256;
	pixel = ((data->sprite_calc.tex.y * data->sprite.img.line_len) +
			data->sprite_calc.tex.x * (data->sprite.img.bits_per_pixel / 8));
	color = *(unsigned int *)(data->sprite.img.addr + pixel);
	if (data->move_counter % 2 != 0)
	{
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&data->mlx.first_img, x, y, color);
	}
	if (data->move_counter % 2 == 0)
	{
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&data->mlx.second_img, x, y, color);
	}
}

void		draw_sprite(t_data *data)
{
	int	stripe;
	int	y;

	stripe = data->sprite_calc.draw_start.x;
	while (stripe < data->sprite_calc.draw_end.x)
	{
		set_tex_x(data, stripe);
		y = data->sprite_calc.draw_start.y;
		if (data->sprite_calc.transform.y > 0 && stripe > 0 &&
						stripe < data->file.res.x &&
						data->sprite_calc.transform.y < data->zbuffer[stripe])
		{
			while (y < data->sprite_calc.draw_end.y)
			{
				draw_sprite_pixel(data, stripe, y);
				y++;
			}
		}
		stripe++;
	}
}
