/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:39:20 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:39:21 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player_position(t_data *data)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x] != '\0')
		{
			c = data->file.map[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				data->ray.player_pos.x = x + 0.5;
				data->ray.player_pos.y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}
