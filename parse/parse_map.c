/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:16:27 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_and_exit(char *line, t_data *data)
{
	free(line);
	free_texture_paths(data);
	exit_error(MALLOC_FAIL);
}

static char	*ft_copy_add_newline(char *line, t_data *data)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	len = ft_strlen(line);
	new_line = malloc(len + 2);
	if (!new_line)
		free_and_exit(line, data);
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[len] = '\n';
	new_line[len + 1] = '\0';
	free(line);
	return (new_line);
}

static char	*ft_join_free_add_newline(char *str_map, char *line, t_data *data,
																		int i)
{
	char	*new_str_map;
	int		x;

	new_str_map = malloc(ft_strlen(str_map) + ft_strlen(line) + 2);
	if (!new_str_map)
	{
		free(str_map);
		free_and_exit(line, data);
	}
	x = 0;
	while (str_map[i] != '\0')
	{
		new_str_map[i] = str_map[i];
		i++;
	}
	free(str_map);
	while (line[x] != '\0')
	{
		new_str_map[i + x] = line[x];
		x++;
	}
	free(line);
	new_str_map[i + x] = '\n';
	new_str_map[i + x + 1] = '\0';
	return (new_str_map);
}

static void	check_double_newline(t_data *data, char *str_map)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str_map);
	while (str_map[i] != '\0')
	{
		if (str_map[i] == '\n' && str_map[i - 1] == '\n' && i != (str_len - 1))
		{
			free(str_map);
			exit_data_error(data, INVALID_MAP);
		}
		i++;
	}
}

void		parse_map(int fd, char *line, t_data *data)
{
	char	*str_map;

	str_map = ft_copy_add_newline(line, data);
	while (get_next_line(fd, &line))
		str_map = ft_join_free_add_newline(str_map, line, data, 0);
	str_map = ft_join_free_add_newline(str_map, line, data, 0);
	check_double_newline(data, str_map);
	data->file.map = ft_split(str_map, '\n');
	if (!data->file.map)
	{
		free(str_map);
		free_texture_paths(data);
		exit_error(MALLOC_FAIL);
	}
	free(str_map);
	close(fd);
}
