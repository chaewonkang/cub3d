/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 08:44:24 by gbouwen       #+#    #+#                 */
/*   Updated: 2019/11/20 14:15:07 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_start_pos(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	if (i == (int)ft_strlen(s1))
		return (-1);
	return (i);
}

static int	get_end_pos(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i + 1);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		i;
	char	*new_str;

	if (s1 == 0)
		return (0);
	start = get_start_pos(s1, set);
	if (start == -1)
		return (ft_strdup(""));
	end = get_end_pos(s1, set);
	i = 0;
	new_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!new_str)
		return (0);
	while (start < end)
	{
		new_str[i] = ((char *)s1)[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
