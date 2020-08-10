/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_from_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:39:49 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:39:49 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprite_from_file(t_data *data)
{
	data->sprite.img.img = mlx_xpm_file_to_image(data->mlx.mlx,
								data->file.sprite_ptt, &data->sprite.img_width,
													&data->sprite.img_height);
	if (data->sprite.img.img == NULL)
		exit_image_error(data, INVALID_IMAGE);
	data->sprite.img.addr =
		mlx_get_data_addr(data->sprite.img.img,
						&data->sprite.img.bits_per_pixel,
						&data->sprite.img.line_len, &data->sprite.img.endian);
	if (data->sprite.img.addr == NULL)
		exit_image_error(data, INVALID_IMAGE_ADDRESS);
}
