/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:16:56 by ckang            ###   ########.fr       */
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
