/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:50:12 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/15 11:35:23 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s_dst;
	const char	*s_src;
	size_t		i;

	if (!dst && !src)
		return (0);
	s_dst = dst;
	s_src = src;
	i = 0;
	while (i < n)
	{
		s_dst[i] = s_src[i];
		i++;
	}
	return (dst);
}
