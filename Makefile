# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 12:11:55 by fballest          #+#    #+#              #
#    Updated: 2021/03/26 12:42:17 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS DISCLAIMER #
.DELETE_ON_ERROR:


# FILES NAMES #
NAME = checker
NAME2 = push_swap

# SOURCES #
SRC = checker checker_2
SRC2 = 

SRCCHE = $(addsuffix .c, $(SRC))
SRCPSW = $(addsuffix .c, $(SRC2))
OBJS = $(SRCCHE:.c=.o)
OBJS2 = $(SRCPSW:.c=.o)


LIBFT = libft/libft.a

# COMPILER #
CC = gcc -Wall -Wextra -Werror -g

# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# COMPILING AND CLEANING INSTRUCTIONS #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(OBJS2)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make re
	@echo "$(BLUE)==========CREATING CHECKER==========$(RESET)"
	@$(CC) ${OBJS} $(LIBFT) -o ${NAME}
	@echo "Done"
	# @echo "$(BLUE)==========CREATING PUSH_SWAP==========$(RESET)"
	# @$(CC) ${OBJS2} $(LIBFT) -o ${NAME2}
	# @echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating checker and push_swap files"

clean:
	@$(RM) $(OBJS)
	@make -C libft/ clean
	@$(RM) ${LIBFT}
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning of checker"

fclean: clean
	@$(RM) ${NAME}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning"

re : fclean all

.PHONY: all clean fclean re shell addsuffix
