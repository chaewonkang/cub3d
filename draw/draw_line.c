/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:41:58 by seogkim           #+#    #+#             */
/*   Updated: 2020/11/07 20:11:54 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_line(t_data *data, int x)
{
	set_texture_variables(data);
	draw_ceiling(data, x);
	draw_wall(data, x);
	draw_floor(data, x);
}

void		draw_vertical_line(t_data *data, int x)
{
	data->draw.line_height = (int)(data->file.res.y / data->ray.perp_wall_dist);
	data->draw.start = (-data->draw.line_height / 2) + (data->file.res.y / 2);
	if (data->draw.start < 0)
		data->draw.start = 0;
	data->draw.end = (data->draw.line_height / 2) + (data->file.res.y / 2);
	if (data->draw.end >= data->file.res.y)
		data->draw.end = data->file.res.y - 1;
	draw_line(data, x);
}
