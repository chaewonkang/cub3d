# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seogkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 15:34:19 by seogkim           #+#    #+#              #
#    Updated: 2020/08/10 15:34:36 by seogkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SOURCE_C = 	main.c \
			check_cmdline/check_cmdline.c \
			exit_error/exit_error.c \
			parse/parse_file.c \
			parse/fill_data.c \
			parse/parse_line.c \
			parse/parse_line_utils.c \
			parse/parse_map.c \
			parse/check_data_values.c \
			parse/check_valid_map.c \
			parse/check_valid_map_utils.c \
			parse/get_path_to_texture_utils.c \
			free/free_functions.c \
			mlx_utils/mlx_utils.c \
			render/render_first_frame.c \
			render/get_player_position.c \
			render/get_direction_vector.c \
			render/set_camera_plane.c \
			render/cast_ray.c \
			render/render_screen.c \
			draw/draw_line.c \
			draw/get_color.c \
			draw/draw_map.c \
			draw/draw_texture_pixel.c \
			draw/draw_sprite.c \
			hooks/hooks.c \
			move/move.c \
			move/turn.c \
			textures/get_textures_from_files.c \
			textures/set_texture_variables.c \
			sprites/get_sprite_from_file.c \
			sprites/count_sprites.c \
			sprites/get_sprite_positions.c \
			sprites/handle_sprites.c \
			sprites/calc_dist_from_sprites_to_player.c \
			sprites/sort_sprites.c \
			screenshot/screenshot.c \

SOURCE_O = $(SOURCE_C:.c=.o)

NORMAL = \033[38;5;255m
GREEN = \033[38;5;2m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

all: $(NAME)

$(NAME): $(SOURCE_O)
	@echo "$(BLUE)Making the libft library...$(NORMAL)"
	@make bonus -C lft
	@echo "$(GREEN)Successfully made the libft library!$(NORMAL)"
	@echo "$(BLUE)Making the get_next_line library...$(NORMAL)"
	@make -C gnl
	@echo "$(GREEN)Successfully made the get_next_line library!$(NORMAL)"
	@echo "$(BLUE)Making the mlx library...$(NORMAL)"
	@make -C mlx
	@cp mlx/libmlx.dylib .
	@echo "$(GREEN)Successfully made the mlx library!$(NORMAL)"
	gcc -Wall -Wextra -Werror -Lmlx -lmlx -Llft -lft -Lgnl -lgnl \
	-framework OpenGL -framework Appkit -o $(NAME) $(SOURCE_O)

%.o: %.c
	@echo "$(GREEN)Compiling:$(NORMAL)"
	gcc -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	@/bin/rm -f $(SOURCE_O)
	@/bin/rm -f libmlx.dylib
	@make clean -C lft
	@make clean -C gnl
	@make clean -C mlx

fclean:	clean
	@make fclean -C lft
	@make fclean -C gnl
	@echo "$(RED)Removing executable...$(NORMAL)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)Successfully removed executable!$(NORMAL)"

re: fclean all

.PHONY: all clean clean re
