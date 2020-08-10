/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:16:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2019/11/20 13:01:08 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_n_size(int n)
{
	int	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*put_in_array(char *result, int i, int n, int size)
{
	if (n == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		n = 147483648;
	}
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		result[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	result[size] = '\0';
	return (result);
}

char		*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*result;

	size = get_n_size(n);
	i = size - 1;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	result = put_in_array(result, i, n, size);
	return (result);
}
