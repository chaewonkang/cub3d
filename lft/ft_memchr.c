/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 10:57:47 by gbouwen       #+#    #+#                 */
/*   Updated: 2019/11/21 15:43:22 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *u_s;
	size_t				i;

	u_s = s;
	i = 0;
	while (i < n)
	{
		if (u_s[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
