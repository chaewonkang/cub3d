/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:17:37 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "lft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include "structs.h"
# include "definitions.h"

/*
** CHECK_CMDLINE ---------------------------------------------------------------
*/

void		check_cmdline(int ac, char **av, t_data *data);

/*
** EXIT_ERROR ------------------------------------------------------------------
*/

void		exit_error_cmdline(int error_code);
void		exit_error(int error_code);
void		exit_data_error(t_data *data, int error_code);
void		exit_image_error(t_data *data, int error_code);

/*
** PARSE -----------------------------------------------------------------------
*/

void		parse_file(char **av, t_data *data);
void		fill_data(int fd, t_data *data);
int			parse_line(char *line, t_data *data);
void		parse_map(int fd, char *line, t_data *data);
void		check_data_values(t_data *data);

int			ft_atoi_resolution(const char *str);
int			count_elements(char **elements);
void		check_numbers(char **elements, t_data *data, int start);
void		check_elements(t_data *data, char **elements, int correct_amount);
void		free_all(char **elements);

void		strdup_filename_in_data(t_data *data, char *filename, int id);
void		filename_with_spaces_in_data(t_data *data, char *line, int id);

void		check_valid_map(t_data *data);
void		check_amount_of_players(t_data *data);
t_xy_int	get_player_pos(t_data *data);
int			get_amount_of_rows(t_data *data);
char		**copy_map(int map_rows, t_data *data);

/*
** FREE ------------------------------------------------------------------------
*/

void		free_texture_paths(t_data *data);
void		free_data(t_data *data);

/*
** MLX_UTILS -------------------------------------------------------------------
*/

void		my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);
void		setup_mlx(t_data *data);
void		close_screen_mlx(t_data *data);
void		get_correct_resolution(t_data *data);

/*
** RENDER ----------------------------------------------------------------------
*/

void		render_first_frame(t_data *data);
void		get_player_position(t_data *data);
void		get_direction_vector(t_data *data);
void		set_camera_plane(t_data *data);
void		render_screen(t_data *data);
void		cast_ray(t_data *data, int x);
void		create_second_image(t_data *data);

/*
** DRAW ------------------------------------------------------------------------
*/

void		draw_vertical_line(t_data *data, int x);
int			get_color(t_color color);

void		draw_ceiling(t_data *data, int x);
void		draw_wall(t_data *data, int x);
void		draw_floor(t_data *data, int x);
void		draw_sprite(t_data *data);

void		draw_north_texture_pixel(t_data *data, int x, int y);
void		draw_south_texture_pixel(t_data *data, int x, int y);
void		draw_west_texture_pixel(t_data *data, int x, int y);
void		draw_east_texture_pixel(t_data *data, int x, int y);

/*
** HOOKS -----------------------------------------------------------------------
*/

int			key_press(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);
int			close_window(t_data *data);
int			handle_movement(t_data *data);

/*
** MOVE ------------------------------------------------------------------------
*/

void		move_forward(t_data *data);
void		move_backward(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

void		turn_left(t_data *data);
void		turn_right(t_data *data);

/*
** TEXTURE ---------------------------------------------------------------------
*/

void		get_textures_from_files(t_data *data);
void		set_texture_variables(t_data *data);

/*
** SPRITES ---------------------------------------------------------------------
*/

void		get_sprite_from_file(t_data *data);
void		count_sprites(t_data *data);
void		get_sprite_positions(t_data *data);
void		handle_sprites(t_data *data);
void		calc_dist_from_sprites_to_player(t_data *data);
void		sort_sprites(t_data *data);

/*
** SCREENSHOT ------------------------------------------------------------------
*/

void		screenshot(t_data *data);

#endif
