/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:16:18 by ckang            ###   ########.fr       */
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
