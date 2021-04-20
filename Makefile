# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 12:11:55 by fballest          #+#    #+#              #
#    Updated: 2021/04/20 13:05:36 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS DISCLAIMER #
.DELETE_ON_ERROR:


# FILES NAMES #
NAME = checker
NAME2 = push_swap

# SOURCES #
SRC = checker checker_1 checker_2 checker_3 checker_4 checker_5
SRC2 = pusher pusher_1 checker_1 checker_2 checker_3 checker_4 \
		checker_5

SRCCHE = $(addsuffix .c, $(SRC))
SRCPSW = $(addsuffix .c, $(SRC2))
OBJS = $(SRCCHE:.c=.o)
OBJS2 = $(SRCPSW:.c=.o)


LIBFT = libft/libft.a

# COMPILER #
CC = cc -Wall -Wextra -Werror -g #3 -fsanitize=address -O0

# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# COMPILING AND CLEANING INSTRUCTIONS #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(OBJS2)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make
	@echo "$(BLUE)==========CREATING CHECKER==========$(RESET)"
	@$(CC) ${OBJS} $(LIBFT) -o ${NAME}
	@echo "Done checker file"
	@echo "$(BLUE)==========CREATING PUSH_SWAP==========$(RESET)"
	@$(CC) ${OBJS2} $(LIBFT) -o ${NAME2}
	@echo "Done push_swap file"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating checker and push_swap files"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS2)
	@$(RM) ${NAME}
	@$(RM) ${NAME2}
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning of checker"

fclean: clean
	@$(RM) $(OBJS)
	@$(RM) $(OBJS2)
	@make -C libft/ fclean
	@$(RM) ${LIBFT}
	@$(RM) ${NAME}
	@$(RM) ${NAME2}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning"

re : clean all

.PHONY: all clean fclean re shell addsuffix
