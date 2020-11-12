/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_first_frame.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:16:59 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_raycast_variables(t_data *data)
{
	data->ray.player_pos.x = 0.0;
	data->ray.player_pos.y = 0.0;
	data->ray.dir_vec.x = 0.0;
	data->ray.dir_vec.y = 0.0;
	data->ray.camera_plane.x = 0.0;
	data->ray.camera_plane.y = 0.0;
	data->ray.camera_x = 0.0;
	data->ray.ray_dir.x = 0.0;
	data->ray.ray_dir.y = 0.0;
	data->ray.box_map.x = 0;
	data->ray.box_map.y = 0;
	data->ray.side_dist.x = 0.0;
	data->ray.side_dist.y = 0.0;
	data->ray.delta_dist.x = 0.0;
	data->ray.delta_dist.y = 0.0;
	data->ray.perp_wall_dist = 0.0;
	data->ray.step.x = 0;
	data->ray.step.y = 0;
	data->ray.hit = 0;
	data->ray.side = 0;
}

static void	init_move_turn_variables(t_data *data)
{
	data->move.forward = 0;
	data->move.backward = 0;
	data->move.left = 0;
	data->move.right = 0;
	data->turn.left = 0;
	data->turn.right = 0;
	data->move_counter = 1;
}

static void	init_zbuffer(t_data *data)
{
	data->zbuffer = ft_calloc(data->file.res.x, sizeof(double));
	if (data->zbuffer == NULL)
	{
		free_texture_paths(data);
		exit_error(MALLOC_FAIL);
	}
}

static void	init_sprites_array(t_data *data)
{
	data->sprites = ft_calloc(data->amount_of_sprites, sizeof(t_sprite_map));
	if (data->sprites == NULL)
	{
		free_texture_paths(data);
		exit_error(MALLOC_FAIL);
	}
}

void		render_first_frame(t_data *data)
{
	get_textures_from_files(data);
	get_sprite_from_file(data);
	init_raycast_variables(data);
	init_move_turn_variables(data);
	init_zbuffer(data);
	count_sprites(data);
	if (data->amount_of_sprites > 0)
		init_sprites_array(data);
	get_player_position(data);
	get_direction_vector(data);
	set_camera_plane(data);
	get_sprite_positions(data);
	if (data->file.save_to_bmp == 0)
		create_second_image(data);
	render_screen(data);
	if (data->file.save_to_bmp == 1)
		screenshot(data);
}
