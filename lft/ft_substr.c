/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:15:22 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		substr = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
