/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:38:23 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:38:24 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		check_amount_of_players(t_data *data)
{
	int		y;
	int		x;
	char	c;
	int		amount_of_players;

	y = 0;
	amount_of_players = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x] != '\0')
		{
			c = data->file.map[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				amount_of_players++;
			x++;
		}
		y++;
	}
	if (amount_of_players != 1)
		exit_data_error(data, INVALID_PLAYER_AMOUNT);
}

t_xy_int	get_player_pos(t_data *data)
{
	int			y;
	int			x;
	char		c;
	t_xy_int	player_pos;

	y = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x] != '\0')
		{
			c = data->file.map[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				player_pos.x = x;
				player_pos.y = y;
			}
			x++;
		}
		y++;
	}
	return (player_pos);
}

int			get_amount_of_rows(t_data *data)
{
	int	y;

	y = 0;
	while (data->file.map[y] != NULL)
		y++;
	return (y);
}

char		**copy_map(int map_rows, t_data *data)
{
	char	**flood_fill_map;
	int		i;

	flood_fill_map = malloc(sizeof(char *) * (map_rows));
	if (!flood_fill_map)
	{
		free_texture_paths(data);
		exit_error(MALLOC_FAIL);
	}
	i = 0;
	while (i < map_rows)
	{
		flood_fill_map[i] = ft_strdup(data->file.map[i]);
		i++;
	}
	return (flood_fill_map);
}
