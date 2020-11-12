/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_from_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:17:19 by ckang            ###   ########.fr       */
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
