# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 12:11:55 by fballest          #+#    #+#              #
#    Updated: 2022/03/11 10:05:13 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS DISCLAIMER #
.DELETE_ON_ERROR:


# FILES NAMES #
NAME = push_swap

# SOURCES #
SRC = push_swap parser parser_2 parser_3 utils utils_2 moves_std moves_std2 \
		moves_std3 solve mem_utils get_position medium_100

SRCCHE = $(addsuffix .c, $(SRC))
OBJS = $(SRCCHE:.c=.o)

LIBFT = libft/libft.a

# COMPILER #
CC = gcc -Wall -Wextra -Werror -g #-fsanitize=address -O3

# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# COMPILING AND CLEANING INSTRUCTIONS #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make
	@echo "$(BLUE)==========CREATING PUSH_SWAP==========$(RESET)"
	@$(CC) ${OBJS} $(LIBFT) -o ${NAME}
	@echo "Done push_swap file"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating push_swap file"

clean:
	@$(RM) $(OBJS)
	@$(RM) ${NAME}
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning of push_swap"

fclean: clean
	@$(RM) $(OBJS)
	@make -C libft/ fclean
	@$(RM) ${LIBFT}
	@$(RM) ${NAME}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning"

re : clean all

.PHONY: all clean fclean re shell addsuffix
