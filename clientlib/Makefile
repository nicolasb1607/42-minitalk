# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 16:22:47 by nburat-d          #+#    #+#              #
#    Updated: 2022/01/18 16:22:48 by nburat-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = client
LIB = libft.a
PATH_TO_LIB = ../libft/

SRCS = ./main.c ./handler.c

INCLUDES = ./includes/

OBJS = ${SRCS:.c=.o}

BLUE=\033[34m
YEL=\033[33m

all : $(EXEC)
	@echo "$(BLUE)Compilation client DONE\n"

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -L $(PATH_TO_LIB) $^ -I $(INCLUDES) -lft -o $(EXEC)

.o : .c
	@$(CC) $(CFLAGS) -c -L $(PATH_TO_LIB) $^ -o $@ -I $(INCLUDES) -lft

clean :
	rm -rf $(OBJS)
	@echo "$(YEL)Client clean DONE\n"

fclean : clean
	rm -rf $(EXEC)
	@echo "$(YEL)Client fclean DONE\n"
re : fclean all

.PHONY : all clean fclean

.SILENT : 

