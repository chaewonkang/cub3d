/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 11:13:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/24 16:16:17 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	create_file(t_data *data)
{
	data->bmp_file_fd =
		open("./bmp_file/screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (data->bmp_file_fd == -1)
		exit_error(INVALID_FD_OPEN);
}

static void	set_bmp_file_header(t_data *data)
{
	char	bmp_file_header[14];
	int		write_val;

	bmp_file_header[0] = 'B';
	bmp_file_header[1] = 'M';
	*(unsigned int *)(bmp_file_header + 2) =
								54 + (3 * data->file.res.x * data->file.res.y);
	*(short *)(bmp_file_header + 6) = 0;
	*(short *)(bmp_file_header + 8) = 0;
	*(unsigned int *)(bmp_file_header + 10) = 54;
	write_val = write(data->bmp_file_fd, bmp_file_header, 14);
	if (write_val == -1)
		exit_error(INVALID_WRITE);
}

static void	set_bmp_image_header(t_data *data)
{
	char	bmp_image_header[40];
	int		write_val;

	*(unsigned int *)(bmp_image_header) = 40;
	*(int *)(bmp_image_header + 4) = (int)data->file.res.x;
	*(int *)(bmp_image_header + 8) = (int)data->file.res.y;
	*(short *)(bmp_image_header + 12) = 1;
	*(short *)(bmp_image_header + 14) = 24;
	*(unsigned int *)(bmp_image_header + 16) = 0;
	*(unsigned int *)(bmp_image_header + 20) = 0;
	*(unsigned int *)(bmp_image_header + 24) = 0;
	*(unsigned int *)(bmp_image_header + 28) = 0;
	*(unsigned int *)(bmp_image_header + 32) = 0;
	*(unsigned int *)(bmp_image_header + 36) = 0;
	write_val = write(data->bmp_file_fd, bmp_image_header, 40);
	if (write_val == -1)
		exit_error(INVALID_WRITE);
}

static void	write_pixels_to_file(t_data *data)
{
	int				x;
	int				y;
	char			*pix_addr;
	unsigned int	pixel;
	int				write_val;

	y = data->file.res.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->file.res.x)
		{
			pix_addr = data->mlx.first_img.addr +
									(y * data->mlx.first_img.line_len + x *
									(data->mlx.first_img.bits_per_pixel / 8));
			pixel = *(unsigned int *)pix_addr;
			write_val = write(data->bmp_file_fd, &pixel, 3);
			if (write_val == -1)
				exit_error(INVALID_WRITE);
			x++;
		}
		y--;
	}
}

void		screenshot(t_data *data)
{
	create_file(data);
	set_bmp_file_header(data);
	set_bmp_image_header(data);
	write_pixels_to_file(data);
	close_screen_mlx(data);
}
