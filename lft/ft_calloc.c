/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 10:32:47 by gbouwen       #+#    #+#                 */
/*   Updated: 2019/11/20 13:38:03 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_calloc(size_t count, size_t size)
{
	void	*space;
	size_t	i;

	space = (void *)malloc(count * size);
	if (!space)
		return (0);
	i = 0;
	while (i < (count * size))
	{
		((char *)space)[i] = 0;
		i++;
	}
	return (space);
}
