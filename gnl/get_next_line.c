/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:22:58 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:12:20 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*file;
	static int	start_pos = 0;
	static int	pos_n = 0;
	int			val_read;

	val_read = first_read(fd, &file, &start_pos, &pos_n);
	if (val_read == -1)
		return (-1);
	if (val_read == -2)
	{
		*line = ft_strdup_gnl("");
		return (0);
	}
	if (pos_n == -1 && val_read == 1)
		*line = read_until_newline(fd, &file, start_pos, &pos_n);
	else
		*line = get_correct_line(file, start_pos, pos_n);
	if (*line == NULL)
		return (-1);
	if (pos_n == -1)
		return (free_and_zero(file));
	pos_n++;
	return (1);
}

int		first_read(int fd, char **file, int *start_pos, int *pos_n)
{
	char	temp[1 + 1];
	int		val_read;

	if (fd == -1)
		return (-1);
	val_read = read(fd, temp, 1);
	if (val_read == -1)
		return (-1);
	if (val_read == 0 && *pos_n == 0)
		return (-2);
	temp[val_read] = '\0';
	*start_pos = *pos_n;
	if (val_read > 0)
	{
		if (!*file)
			*file = ft_strdup_gnl(temp);
		else
			*file = ft_join_free(*file, temp);
	}
	if (*file == NULL)
		return (-1);
	*pos_n = get_pos_n(*file, *start_pos);
	return (val_read);
}

char	*read_until_newline(int fd, char **file, int start_pos, int *pos_n)
{
	char	temp[1 + 1];
	int		val_read;
	char	*correct_line;

	val_read = 1;
	while (*pos_n == -1 && val_read == 1)
	{
		val_read = read(fd, temp, 1);
		temp[val_read] = '\0';
		if (val_read > 0)
			*file = ft_join_free(*file, temp);
		if (*file == NULL)
			return (NULL);
		*pos_n = get_pos_n(*file, start_pos);
	}
	correct_line = get_correct_line(*file, start_pos, *pos_n);
	return (correct_line);
}

char	*get_correct_line(char *file, int start_pos, int pos_n)
{
	int		len_last_line;
	char	*str;

	if (pos_n == -1)
	{
		len_last_line = ft_strlen_v2(file, start_pos);
		str = malloc(len_last_line + 1);
	}
	else
		str = malloc(pos_n - start_pos + 1);
	if (!str)
	{
		free(file);
		return (NULL);
	}
	str = ft_cpy(str, file, start_pos, pos_n);
	return (str);
}

int		free_and_zero(char *file)
{
	free(file);
	return (0);
}
