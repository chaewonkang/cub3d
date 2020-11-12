/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:16:11 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_elements_table(int amount_of_elements[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		amount_of_elements[i] = 0;
		i++;
	}
}

static void	check_elem_amt(int amount_of_elements[8], char *line, t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (amount_of_elements[i] != 1)
		{
			free(line);
			free_texture_paths(data);
			exit_error(INVALID_TOTAL_ELEMENT_AMOUNT);
		}
		i++;
	}
}

void		fill_data(int fd, t_data *data)
{
	int		amount_of_elements[8];
	char	*line;
	int		id;

	init_elements_table(amount_of_elements);
	while (get_next_line(fd, &line))
	{
		id = parse_line(line, data);
		if (id == ERROR)
		{
			free(line);
			free_texture_paths(data);
			exit_error(INVALID_LINE);
		}
		if (id == MAP)
			break ;
		if (id != ERROR && id != MAP && id != EMPTY_LINE)
			amount_of_elements[id]++;
		free(line);
	}
	check_elem_amt(amount_of_elements, line, data);
	parse_map(fd, line, data);
}
