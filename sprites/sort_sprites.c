/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:17:27 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	swap(t_sprite_map *sprites_a, t_sprite_map *sprites_b)
{
	t_sprite_map temp;

	temp = *sprites_a;
	*sprites_a = *sprites_b;
	*sprites_b = temp;
}

void		sort_sprites(t_data *data)
{
	int	i;
	int	x;

	i = 0;
	while (i < (data->amount_of_sprites - 1))
	{
		x = 0;
		while (x < (data->amount_of_sprites - i - 1))
		{
			if (data->sprites[x].dist_to_player <
					data->sprites[x + 1].dist_to_player)
				swap(&data->sprites[x], &data->sprites[x + 1]);
			x++;
		}
		i++;
	}
}
