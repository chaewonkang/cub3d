/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <ckang@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:17 by seogkim           #+#    #+#             */
/*   Updated: 2020/11/07 20:12:07 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_error_cmdline(int error_code)
{
	ft_putstr_fd("Error:\n", 2);
	if (error_code == INVALID_ARGUMENT_AMOUNT)
		ft_putstr_fd("Invalid argument amount. 2 or 3 arguments needed.\n", 2);
	if (error_code == INVALID_FILE_FORMAT)
		ft_putstr_fd("Invalid file format. Use a .cub file.\n", 2);
	if (error_code == INVALID_ARGUMENT)
		ft_putstr_fd("Invalid argument. Third argument should be --save.\n", 2);
	exit(0);
}

void	exit_error(int error_code)
{
	ft_putstr_fd("Error:\n", 2);
	if (error_code == INVALID_ARGUMENT_AMOUNT)
		ft_putstr_fd("Invalid argument amount. 2 or 3 arguments needed.\n", 2);
	if (error_code == INVALID_FILE_FORMAT)
		ft_putstr_fd("Invalid file format. Use a .cub file.\n", 2);
	if (error_code == INVALID_ARGUMENT)
		ft_putstr_fd("Invalid argument. Third argument should be --save.\n", 2);
	if (error_code == INVALID_FD)
		ft_putstr_fd("Invalid file descriptor. Could not open the file.\n", 2);
	if (error_code == INVALID_LINE)
		ft_putstr_fd("Invalid line in file. Could not recognize element.\n", 2);
	if (error_code == INVALID_TOTAL_ELEMENT_AMOUNT)
		ft_putstr_fd("Invalid element amount. Include each element once.\n", 2);
	if (error_code == MALLOC_FAIL)
		ft_putstr_fd("Malloc failed.\n", 2);
	if (error_code == INVALID_ELEMENT_FORMAT)
		ft_putstr_fd("Invalid element format. Check each element.\n", 2);
	if (error_code == INVALID_FD_OPEN)
		ft_putstr_fd("Invalid file descriptor. Could not create bitmap.\n", 2);
	if (error_code == INVALID_WRITE)
		ft_putstr_fd("Invalid write. Could not write to bitmap.\n", 2);
	if (error_code == INVALID_CHARACTER)
		ft_putstr_fd("Invalid character at resolution, floor or ceiling.\n", 2);
	exit(0);
}

void	exit_data_error(t_data *data, int error_code)
{
	ft_putstr_fd("Error:\n", 2);
	if (error_code == INVALID_RESOLUTION)
		ft_putstr_fd("Invalid resolution. Resolution must be > 0.\n", 2);
	if (error_code == INVALID_NORTH_PTT)
		ft_putstr_fd("Invalid path to north texture.\n", 2);
	if (error_code == INVALID_SOUTH_PTT)
		ft_putstr_fd("Invalid path to south texture.\n", 2);
	if (error_code == INVALID_WEST_PTT)
		ft_putstr_fd("Invalid path to west texture.\n", 2);
	if (error_code == INVALID_EAST_PTT)
		ft_putstr_fd("Invalid path to east texture.\n", 2);
	if (error_code == INVALID_SPRITE_PTT)
		ft_putstr_fd("Invalid path to sprite texture.\n", 2);
	if (error_code == INVALID_FLOOR_COLOR)
		ft_putstr_fd("Invalid floor color. Must be in range [0-255].\n", 2);
	if (error_code == INVALID_CEILING_COLOR)
		ft_putstr_fd("Invalid ceiling color. Must be in range [0-255].\n", 2);
	if (error_code == INVALID_MAP)
		ft_putstr_fd("Invalid map. Check the rules for the map.\n", 2);
	if (error_code == INVALID_PLAYER_AMOUNT)
		ft_putstr_fd("Invalid player amount. Player can only occur once.\n", 2);
	if (error_code == INVALID_SCREENSHOT_SIZE)
		ft_putstr_fd("Invalid resolution. Maximum dimension is 16384.\n", 2);
	free_texture_paths(data);
	exit(0);
}

void	exit_image_error(t_data *data, int error_code)
{
	ft_putstr_fd("Error:\n", 2);
	if (error_code == INVALID_IMAGE)
		ft_putstr_fd("Invalid image. Could not open the texture file.\n", 2);
	if (error_code == INVALID_IMAGE_ADDRESS)
		ft_putstr_fd("Invalid address. Could not get the image address.\n", 2);
	free_texture_paths(data);
	exit(0);
}
