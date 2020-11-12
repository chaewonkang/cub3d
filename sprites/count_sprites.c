/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:17:16 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	count_sprites(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->amount_of_sprites = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x] != '\0')
		{
			if (data->file.map[y][x] == '2')
				data->amount_of_sprites++;
			x++;
		}
		y++;
	}
}
