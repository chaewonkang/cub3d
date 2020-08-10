/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:38:47 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:38:48 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_atoi_resolution(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if ((result * sign) > 16834)
			return (result * sign);
		i++;
	}
	if ((result * sign) > 0)
		return (result * sign);
	return (-1);
}

int			count_elements(char **elements)
{
	int	i;

	i = 0;
	while (elements[i] != NULL)
		i++;
	return (i);
}

void		check_numbers(char **elements, t_data *data, int start)
{
	int	i;
	int	x;

	i = start;
	x = 0;
	while (elements[i] != NULL)
	{
		x = 0;
		while (elements[i][x] != '\0')
		{
			if (elements[i][x] >= '0' && elements[i][x] <= '9')
				x++;
			else
			{
				free_texture_paths(data);
				exit_error(INVALID_CHARACTER);
			}
		}
		i++;
	}
}

void		check_elements(t_data *data, char **elements, int correct_amount)
{
	if (!elements)
	{
		free_texture_paths(data);
		exit_error(MALLOC_FAIL);
	}
	if (count_elements(elements) != correct_amount)
	{
		free_texture_paths(data);
		exit_error(INVALID_ELEMENT_FORMAT);
	}
}

void		free_all(char **elements)
{
	int	i;

	i = count_elements(elements);
	while (i >= 0)
	{
		if (elements[i])
			free(elements[i]);
		i--;
	}
	if (elements)
		free(elements);
}
