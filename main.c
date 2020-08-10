/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:37:29 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:37:30 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data data;

	check_cmdline(ac, av, &data);
	parse_file(av, &data);
	setup_mlx(&data);
	render_first_frame(&data);
	mlx_hook(data.mlx.win, 17, 1L << 17, &close_window, &data);
	mlx_hook(data.mlx.win, KEY_PRESS, 1L << 0, &key_press, &data);
	mlx_hook(data.mlx.win, KEY_RELEASE, 1L << 1, &key_release, &data);
	mlx_loop_hook(data.mlx.mlx, &handle_movement, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
