/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:38:43 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:38:44 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		get_resolution(char *line, t_data *data, int id)
{
	char	**elements;

	elements = ft_split(line, ' ');
	check_elements(data, elements, 3);
	check_numbers(elements, data, 1);
	data->file.res.x = ft_atoi_resolution(elements[1]);
	data->file.res.y = ft_atoi_resolution(elements[2]);
	free_all(elements);
	return (id);
}

static int		get_path_to_texture_or_sprite(char *line, t_data *data, int id)
{
	char	**elements;

	elements = ft_split(line, ' ');
	if (count_elements(elements) == 2)
		strdup_filename_in_data(data, elements[1], id);
	if (count_elements(elements) > 2)
		filename_with_spaces_in_data(data, line, id);
	free_all(elements);
	return (id);
}

static t_color	get_rgb_color(t_data *data, char *color_elements)
{
	char	**elements;
	t_color	rgb_values;

	elements = ft_split(color_elements, ',');
	check_elements(data, elements, 3);
	check_numbers(elements, data, 0);
	rgb_values.red = ft_atoi(elements[0]);
	rgb_values.green = ft_atoi(elements[1]);
	rgb_values.blue = ft_atoi(elements[2]);
	free_all(elements);
	return (rgb_values);
}

static int		get_floor_ceiling(char *line, t_data *data, int id)
{
	char	**elements;

	elements = ft_split(line, ' ');
	check_elements(data, elements, 2);
	if (id == FLOOR)
		data->file.floor_color = get_rgb_color(data, elements[1]);
	if (id == CEILING)
		data->file.ceiling_color = get_rgb_color(data, elements[1]);
	free_all(elements);
	return (id);
}

int				parse_line(char *line, t_data *data)
{
	int	id;

	id = ERROR;
	if (ft_strncmp("R ", line, 2) == 0)
		id = get_resolution(line, data, RESOLUTION);
	if (ft_strncmp("NO ", line, 3) == 0)
		id = get_path_to_texture_or_sprite(line, data, NORTH);
	if (ft_strncmp("SO ", line, 3) == 0)
		id = get_path_to_texture_or_sprite(line, data, SOUTH);
	if (ft_strncmp("WE ", line, 3) == 0)
		id = get_path_to_texture_or_sprite(line, data, WEST);
	if (ft_strncmp("EA ", line, 3) == 0)
		id = get_path_to_texture_or_sprite(line, data, EAST);
	if (ft_strncmp("S ", line, 2) == 0)
		id = get_path_to_texture_or_sprite(line, data, SPRITE);
	if (ft_strncmp("F ", line, 2) == 0)
		id = get_floor_ceiling(line, data, FLOOR);
	if (ft_strncmp("C ", line, 2) == 0)
		id = get_floor_ceiling(line, data, CEILING);
	if (ft_strncmp(" ", line, 1) == 0 || ft_strncmp("1", line, 1) == 0)
		id = MAP;
	if (ft_strncmp("\0", line, 1) == 0)
		id = EMPTY_LINE;
	return (id);
}
