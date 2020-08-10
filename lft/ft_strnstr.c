/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strnstr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:48:15 by gbouwen       #+#    #+#                 */
/*   Updated: 2019/11/21 16:07:17 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_compare(const char *h, const char *n, size_t len)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < len && h[i] != '\0' && n[i] != '\0')
	{
		if (h[i] != n[i])
			return (h[i] - n[i]);
		i++;
	}
	if (n[i] == '\0')
		return (0);
	else
		return (1);
}

char			*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	size_t	i;

	if (needle[0] == 0)
		return ((char *)haystack);
	if (l == 0)
		return (0);
	i = 0;
	while (haystack[i] != '\0' && l > 0)
	{
		if (ft_compare(haystack + i, needle, l) == 0)
			return ((char *)(haystack + i));
		i++;
		l--;
	}
	return (0);
}
