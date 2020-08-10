/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:38:11 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:38:13 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_resolution(t_data *data)
{
	if ((data->file.res.x > 16384 || data->file.res.y > 16384) &&
												data->file.save_to_bmp == 1)
		exit_data_error(data, INVALID_SCREENSHOT_SIZE);
	if (data->file.save_to_bmp == 0)
		get_correct_resolution(data);
	if (data->file.res.x <= 0 || data->file.res.y <= 0)
		return (0);
	return (1);
}

static int	check_color(t_color color)
{
	if (color.red < 0 || color.red > 255)
		return (0);
	if (color.green < 0 || color.green > 255)
		return (0);
	if (color.blue < 0 || color.blue > 255)
		return (0);
	return (1);
}

static int	check_ptt(char *path_to_texture)
{
	int	fd;

	fd = open(path_to_texture, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void		check_data_values(t_data *data)
{
	if (check_resolution(data) == 0)
		exit_data_error(data, INVALID_RESOLUTION);
	if (check_ptt(data->file.north_ptt) == 0)
		exit_data_error(data, INVALID_NORTH_PTT);
	if (check_ptt(data->file.south_ptt) == 0)
		exit_data_error(data, INVALID_SOUTH_PTT);
	if (check_ptt(data->file.west_ptt) == 0)
		exit_data_error(data, INVALID_WEST_PTT);
	if (check_ptt(data->file.east_ptt) == 0)
		exit_data_error(data, INVALID_EAST_PTT);
	if (check_ptt(data->file.sprite_ptt) == 0)
		exit_data_error(data, INVALID_SPRITE_PTT);
	if (check_color(data->file.floor_color) == 0)
		exit_data_error(data, INVALID_FLOOR_COLOR);
	if (check_color(data->file.ceiling_color) == 0)
		exit_data_error(data, INVALID_CEILING_COLOR);
}
