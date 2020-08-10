/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:40:00 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:40:03 by seogkim          ###   ########.fr       */
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
