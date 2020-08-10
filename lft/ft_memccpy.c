/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:33:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2019/11/21 15:36:09 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;
	size_t				i;

	u_dst = dst;
	u_src = src;
	i = 0;
	while (i < n)
	{
		u_dst[i] = u_src[i];
		if (u_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
