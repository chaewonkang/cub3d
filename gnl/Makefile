# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seogkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 15:36:43 by seogkim           #+#    #+#              #
#    Updated: 2020/08/10 15:36:46 by seogkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SOURCE_C = get_next_line.c get_next_line_utils.c

SOURCE_O = $(SOURCE_C:.c=.o)

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

all: $(NAME)

%.o: %.c
	@echo "$(GREEN)Compiling:$(NORMAL)"
	gcc -Wall -Wextra -Werror -c -o $@ $<

$(NAME): $(SOURCE_O)
	@echo "$(BLUE)Adding to library...$(NORMAL)"
	ar rc $(NAME) $(SOURCE_O) $?
	@echo "$(GREEN)Successfully added to library!$(NORMAL)"

clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	/bin/rm -f $(SOURCE_O) $(BONUS_O)
	@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean: clean
	@echo "$(RED)Removing libgnl.a...$(NORMAL)"
	/bin/rm -f $(NAME)
	@echo "$(GREEN)Successfully removed libgnl.a!$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re
