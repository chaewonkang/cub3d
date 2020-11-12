/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:14:57 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s_len;
	char	*new_str;
	size_t	i;

	if (s1 == 0)
		return (0);
	s_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!new_str)
		return (0);
	i = 0;
	while (*s1 != '\0')
	{
		new_str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}
