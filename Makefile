# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 14:30:56 by tsuetsug          #+#    #+#              #
#    Updated: 2021/08/12 11:41:41 by tsuetsug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= srcs/push_swap.c srcs/error_check.c srcs/node_control.c \
			srcs/command_control.c 

OBJ		= *.o

BGREEN	= \033[1;32m
BRED	= \033[1;31m
BYELLOW	= \033[1;33m
BWHITE	= \033[1;37m
OFF 	= \033[1;0m

HEADERS = includes/push_swap.h

LIBFT	= libft/libft.a

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME):
	@echo "$(BWHITE)Compiling libraries...$(OFF)"
	@${MAKE} -C libft
	@echo "$(BGREEN)Libraries done.$(OFF)"

	@echo "$(BWHITE)Compiling push_swap...$(OFF)"
	@$(CC) $(FLAGS) -c $(SRCS) -I$(HEADERS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(BGREEN)push_swap build completed.$(OFF)"

clean:
	@echo "$(BWHITE)Removing object-files...$(OFF)"
	@$(RM) $(OBJ)
	@cd libft && $(MAKE) clean
	@echo "$(BGREEN)Clean done.$(OFF)"

fclean:	clean
	@echo "$(BWHITE)Removing object-files and binary-files...$(OFF)"
	@$(RM) $(NAME)
	@cd libft && $(MAKE) fclean
	@echo "$(BGREEN)Fclean done.$(OFF)"

re:		fclean all