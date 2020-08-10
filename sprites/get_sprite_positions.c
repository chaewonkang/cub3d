/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:39:52 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:39:53 by seogkim          ###   ########.fr       */
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
