/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:38:38 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:38:39 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_texture_paths(t_data *data)
{
	data->file.north_ptt = NULL;
	data->file.south_ptt = NULL;
	data->file.east_ptt = NULL;
	data->file.west_ptt = NULL;
	data->file.sprite_ptt = NULL;
}

void		parse_file(char **av, t_data *data)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_error(INVALID_FD);
	init_texture_paths(data);
	fill_data(fd, data);
	check_data_values(data);
	check_valid_map(data);
}
