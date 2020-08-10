/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:40:35 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:40:36 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_north_texture_variables(t_data *data)
{
	if (data->ray.side == 0)
		data->north.wall_x = data->ray.player_pos.y + data->ray.perp_wall_dist
														* data->ray.ray_dir.y;
	else
		data->north.wall_x = data->ray.player_pos.x + data->ray.perp_wall_dist
														* data->ray.ray_dir.x;
	data->north.wall_x -= floor(data->north.wall_x);
	data->north.tex.x = data->north.wall_x * data->north.img_width;
	if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
		data->north.tex.x = data->north.img_width - data->north.tex.x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir.y < 0)
		data->north.tex.x = data->north.img_width - data->north.tex.x - 1;
	data->north.step = 1.0 * data->north.img_height / data->draw.line_height;
	data->north.tex_pos = (data->draw.start - data->file.res.y / 2 +
								data->draw.line_height / 2) * data->north.step;
}

static void	set_south_texture_variables(t_data *data)
{
	if (data->ray.side == 0)
		data->south.wall_x = data->ray.player_pos.y + data->ray.perp_wall_dist
														* data->ray.ray_dir.y;
	else
		data->south.wall_x = data->ray.player_pos.x + data->ray.perp_wall_dist
														* data->ray.ray_dir.x;
	data->south.wall_x -= floor(data->south.wall_x);
	data->south.tex.x = data->south.wall_x * data->south.img_width;
	if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
		data->south.tex.x = data->south.img_width - data->south.tex.x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir.y < 0)
		data->south.tex.x = data->south.img_width - data->south.tex.x - 1;
	data->south.step = 1.0 * data->south.img_height / data->draw.line_height;
	data->south.tex_pos = (data->draw.start - data->file.res.y / 2 +
								data->draw.line_height / 2) * data->south.step;
}

static void	set_west_texture_variables(t_data *data)
{
	if (data->ray.side == 0)
		data->west.wall_x = data->ray.player_pos.y + data->ray.perp_wall_dist
														* data->ray.ray_dir.y;
	else
		data->west.wall_x = data->ray.player_pos.x + data->ray.perp_wall_dist
														* data->ray.ray_dir.x;
	data->west.wall_x -= floor(data->west.wall_x);
	data->west.tex.x = data->west.wall_x * data->west.img_width;
	if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
		data->west.tex.x = data->west.img_width - data->west.tex.x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir.y < 0)
		data->west.tex.x = data->west.img_width - data->west.tex.x - 1;
	data->west.step = 1.0 * data->west.img_height / data->draw.line_height;
	data->west.tex_pos = (data->draw.start - data->file.res.y / 2 +
								data->draw.line_height / 2) * data->west.step;
}

static void	set_east_texture_variables(t_data *data)
{
	if (data->ray.side == 0)
		data->east.wall_x = data->ray.player_pos.y + data->ray.perp_wall_dist
														* data->ray.ray_dir.y;
	else
		data->east.wall_x = data->ray.player_pos.x + data->ray.perp_wall_dist
														* data->ray.ray_dir.x;
	data->east.wall_x -= floor(data->east.wall_x);
	data->east.tex.x = data->east.wall_x * data->east.img_width;
	if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
		data->east.tex.x = data->east.img_width - data->east.tex.x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir.y < 0)
		data->east.tex.x = data->east.img_width - data->east.tex.x - 1;
	data->east.step = 1.0 * data->east.img_height / data->draw.line_height;
	data->east.tex_pos = (data->draw.start - data->file.res.y / 2 +
								data->draw.line_height / 2) * data->east.step;
}

void		set_texture_variables(t_data *data)
{
	set_north_texture_variables(data);
	set_south_texture_variables(data);
	set_west_texture_variables(data);
	set_east_texture_variables(data);
}
