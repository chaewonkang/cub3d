/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_from_sprites_to_player.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:39:41 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:39:42 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	calc_dist(t_data *data, int player_x, int player_y, int i)
{
	data->sprites[i].dist_to_player =
	(player_x - data->sprites[i].pos.x) * (player_x - data->sprites[i].pos.x) +
	(player_y - data->sprites[i].pos.y) * (player_y - data->sprites[i].pos.y);
}

void		calc_dist_from_sprites_to_player(t_data *data)
{
	int	i;
	int	player_x;
	int	player_y;

	i = 0;
	player_x = data->ray.player_pos.x;
	player_y = data->ray.player_pos.y;
	while (i < data->amount_of_sprites)
	{
		calc_dist(data, player_x, player_y, i);
		i++;
	}
}
