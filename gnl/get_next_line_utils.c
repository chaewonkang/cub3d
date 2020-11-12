/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:12:15 by ckang             #+#    #+#             */
/*   Updated: 2020/11/07 20:12:16 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s1)
{
	int		len;
	char	*s1_dup;
	int		i;

	len = ft_strlen_v2(s1, 0);
	s1_dup = malloc(len + 1);
	if (!s1_dup)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return (s1_dup);
}

char	*ft_join_free(char *file, char *temp)
{
	char	*new_file;
	int		i;
	int		x;

	new_file = malloc((ft_strlen_v2(file, 0) + ft_strlen_v2(temp, 0)) + 1);
	if (!new_file)
	{
		free(file);
		return (NULL);
	}
	i = 0;
	while (file[i] != '\0')
	{
		new_file[i] = file[i];
		i++;
	}
	x = 0;
	while (temp[x] != '\0')
	{
		new_file[i + x] = temp[x];
		x++;
	}
	new_file[i + x] = '\0';
	free(file);
	return (new_file);
}

int		ft_strlen_v2(char *str, int start_pos)
{
	int	i;

	i = start_pos;
	while (str[i] != '\0')
		i++;
	return (i - start_pos);
}

int		get_pos_n(char *file, int start_pos)
{
	int	i;

	i = start_pos;
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_cpy(char *str, char *file, int start_pos, int pos_n)
{
	int	i;
	int	len_last_line;

	i = 0;
	if (pos_n == -1)
	{
		len_last_line = ft_strlen_v2(file, start_pos);
		while (i < len_last_line)
		{
			str[i] = file[start_pos + i];
			i++;
		}
	}
	else
		while ((start_pos + i) < pos_n)
		{
			str[i] = file[start_pos + i];
			i++;
		}
	str[i] = '\0';
	return (str);
}
