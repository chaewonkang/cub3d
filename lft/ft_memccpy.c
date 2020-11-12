/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:21:04 by gbouwen           #+#    #+#             */
/*   Updated: 2020/11/07 20:14:11 by ckang            ###   ########.fr       */
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
