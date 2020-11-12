/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:17:22 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		get_sprite_positions(t_data *data)
{
	int	y;
	int	i;
	int	x;

	y = 0;
	i = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x] != '\0')
		{
			if (data->file.map[y][x] == '2')
			{
				data->sprites[i].pos.y = y;
				data->sprites[i].pos.x = x;
				i++;
			}
			x++;
		}
		y++;
	}
}
