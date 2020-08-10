/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seogkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:30 by seogkim           #+#    #+#             */
/*   Updated: 2020/08/10 15:36:30 by seogkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_texture_paths(t_data *data)
{
	if (data->file.north_ptt)
		free(data->file.north_ptt);
	if (data->file.south_ptt)
		free(data->file.south_ptt);
	if (data->file.west_ptt)
		free(data->file.west_ptt);
	if (data->file.east_ptt)
		free(data->file.east_ptt);
	if (data->file.sprite_ptt)
		free(data->file.sprite_ptt);
}

void	free_data(t_data *data)
{
	free_texture_paths(data);
	if (data->zbuffer)
		free(data->zbuffer);
	if (data->sprites)
		free(data->sprites);
}
