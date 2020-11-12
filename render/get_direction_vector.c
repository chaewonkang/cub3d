/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:16:54 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_direction_vector(t_data *data)
{
	char	c;

	c =
	data->file.map[(int)data->ray.player_pos.y][(int)data->ray.player_pos.x];
	if (c == 'N')
	{
		data->ray.dir_vec.x = 0.0;
		data->ray.dir_vec.y = -1.0;
	}
	if (c == 'S')
	{
		data->ray.dir_vec.x = 0.0;
		data->ray.dir_vec.y = 1.0;
	}
	if (c == 'E')
	{
		data->ray.dir_vec.x = 1.0;
		data->ray.dir_vec.y = 0.0;
	}
	if (c == 'W')
	{
		data->ray.dir_vec.x = -1.0;
		data->ray.dir_vec.y = 0.0;
	}
}
