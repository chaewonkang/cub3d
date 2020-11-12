/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmdline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:11:20 by ckang             #+#    #+#             */
/*   Updated: 2020/11/07 20:11:21 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

static void	check_argument_amount(int ac)
{
	if (ac != 2 && ac != 3)
		exit_error_cmdline(INVALID_ARGUMENT_AMOUNT);
}

static void	check_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".cub", 4) != 0)
		exit_error_cmdline(INVALID_FILE_FORMAT);
}

static void	check_if_save(char *arg, t_data *data)
{
	if (ft_strlen(arg) != 6)
		exit_error(INVALID_ARGUMENT);
	if (ft_strncmp(arg, "--save", 6) == 0)
		data->file.save_to_bmp = 1;
	else
		exit_error_cmdline(INVALID_ARGUMENT);
}

void		check_cmdline(int ac, char **av, t_data *data)
{
	check_argument_amount(ac);
	check_file_extension(av[1]);
	data->file.save_to_bmp = 0;
	if (ac == 3)
		check_if_save(av[2], data);
}
