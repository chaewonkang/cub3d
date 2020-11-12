/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:17:49 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct	s_xy_dbl
{
	double	x;
	double	y;
}				t_xy_dbl;

typedef struct	s_xy_int
{
	int	x;
	int	y;
}				t_xy_int;

typedef struct	s_color
{
	double	red;
	double	green;
	double	blue;
}				t_color;

typedef struct	s_file
{
	t_xy_dbl	res;
	char		*north_ptt;
	char		*south_ptt;
	char		*west_ptt;
	char		*east_ptt;
	char		*sprite_ptt;
	t_color		floor_color;
	t_color		ceiling_color;
	char		**map;
	int			save_to_bmp;
}				t_file;

typedef struct	s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_mlx_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_mlx_img	first_img;
	t_mlx_img	second_img;
}				t_mlx;

typedef struct	s_raycast
{
	t_xy_dbl	player_pos;
	t_xy_dbl	dir_vec;
	t_xy_dbl	camera_plane;
	double		camera_x;
	t_xy_dbl	ray_dir;
	t_xy_int	box_map;
	t_xy_dbl	side_dist;
	t_xy_dbl	delta_dist;
	double		perp_wall_dist;
	t_xy_int	step;
	int			hit;
	int			side;
}				t_raycast;

typedef struct	s_draw
{
	int	line_height;
	int	start;
	int	end;
}				t_draw;

typedef struct	s_move
{
	int	forward;
	int	backward;
	int	left;
	int	right;
}				t_move;

typedef struct	s_turn
{
	int	left;
	int	right;
}				t_turn;

typedef struct	s_texture
{
	t_mlx_img	img;
	int			img_width;
	int			img_height;
	double		wall_x;
	t_xy_int	tex;
	double		step;
	double		tex_pos;
	int			color;
}				t_texture;

typedef struct	s_sprite_img
{
	t_mlx_img	img;
	int			img_width;
	int			img_height;
}				t_sprite_img;

typedef struct	s_sprite_map
{
	t_xy_dbl	pos;
	double		dist_to_player;
}				t_sprite_map;

typedef struct	s_sprite_calc
{
	t_xy_dbl	sprite;
	t_xy_dbl	transform;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	t_xy_int	draw_start;
	t_xy_int	draw_end;
	t_xy_int	tex;
}				t_sprite_calc;

typedef struct	s_data
{
	t_file			file;
	t_mlx			mlx;
	t_raycast		ray;
	t_draw			draw;
	t_move			move;
	t_turn			turn;
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_sprite_img	sprite;
	int				amount_of_sprites;
	double			*zbuffer;
	t_sprite_map	*sprites;
	t_sprite_calc	sprite_calc;
	int				bmp_file_fd;
	int				move_counter;
}				t_data;

#endif
