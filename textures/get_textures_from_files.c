/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_from_files.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:40:20 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:40:24 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_north_texture_from_file(t_data *data)
{
	data->north.img.img = mlx_xpm_file_to_image(data->mlx.mlx,
		data->file.north_ptt, &data->north.img_width, &data->north.img_height);
	if (data->north.img.img == NULL)
		exit_image_error(data, INVALID_IMAGE);
	data->north.img.addr =
		mlx_get_data_addr(data->north.img.img, &data->north.img.bits_per_pixel,
						&data->north.img.line_len, &data->north.img.endian);
	if (data->north.img.addr == NULL)
		exit_image_error(data, INVALID_IMAGE_ADDRESS);
}

static void	get_south_texture_from_file(t_data *data)
{
	data->south.img.img = mlx_xpm_file_to_image(data->mlx.mlx,
		data->file.south_ptt, &data->south.img_width, &data->south.img_height);
	if (data->south.img.img == NULL)
		exit_image_error(data, INVALID_IMAGE);
	data->south.img.addr =
		mlx_get_data_addr(data->south.img.img, &data->south.img.bits_per_pixel,
						&data->south.img.line_len, &data->south.img.endian);
	if (data->south.img.addr == NULL)
		exit_image_error(data, INVALID_IMAGE_ADDRESS);
}

static void	get_west_texture_from_file(t_data *data)
{
	data->west.img.img = mlx_xpm_file_to_image(data->mlx.mlx,
		data->file.west_ptt, &data->west.img_width, &data->west.img_height);
	if (data->west.img.img == NULL)
		exit_image_error(data, INVALID_IMAGE);
	data->west.img.addr =
		mlx_get_data_addr(data->west.img.img, &data->west.img.bits_per_pixel,
						&data->west.img.line_len, &data->west.img.endian);
	if (data->west.img.addr == NULL)
		exit_image_error(data, INVALID_IMAGE_ADDRESS);
}

static void	get_east_texture_from_file(t_data *data)
{
	data->east.img.img = mlx_xpm_file_to_image(data->mlx.mlx,
		data->file.east_ptt, &data->east.img_width, &data->east.img_height);
	if (data->east.img.img == NULL)
		exit_image_error(data, INVALID_IMAGE);
	data->east.img.addr =
		mlx_get_data_addr(data->east.img.img, &data->east.img.bits_per_pixel,
						&data->east.img.line_len, &data->east.img.endian);
	if (data->east.img.addr == NULL)
		exit_image_error(data, INVALID_IMAGE_ADDRESS);
}

void		get_textures_from_files(t_data *data)
{
	get_north_texture_from_file(data);
	get_south_texture_from_file(data);
	get_west_texture_from_file(data);
	get_east_texture_from_file(data);
}
