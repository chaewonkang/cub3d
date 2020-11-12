/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:15:52 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	setup_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->file.res.x,
									data->file.res.y, "cub3d");
	data->mlx.first_img.img = mlx_new_image(data->mlx.mlx, data->file.res.x,
															data->file.res.y);
	data->mlx.first_img.addr = mlx_get_data_addr(data->mlx.first_img.img,
		&data->mlx.first_img.bits_per_pixel, &data->mlx.first_img.line_len,
												&data->mlx.first_img.endian);
}

void	close_screen_mlx(t_data *data)
{
	free_data(data);
	if (data->mlx.first_img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.first_img.img);
	if (data->mlx.second_img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.second_img.img);
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	exit(0);
}

void	get_correct_resolution(t_data *data)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(data->mlx.mlx, &screen_width, &screen_height);
	if (data->file.res.x > screen_width)
		data->file.res.x = screen_width;
	if (data->file.res.y > screen_height)
		data->file.res.y = screen_height;
}

void	create_second_image(t_data *data)
{
	data->mlx.second_img.img = mlx_new_image(data->mlx.mlx, data->file.res.x,
															data->file.res.y);
	data->mlx.second_img.addr = mlx_get_data_addr(data->mlx.second_img.img,
		&data->mlx.second_img.bits_per_pixel, &data->mlx.second_img.line_len,
												&data->mlx.second_img.endian);
}
