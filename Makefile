# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 16:22:35 by nburat-d          #+#    #+#              #
#    Updated: 2022/01/18 16:22:36 by nburat-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
PATH_TO_LIB = ./libft/
PATH_TO_SERVER = ./serverlib/
PATH_TO_CLIENT = ./clientlib/

UGREEN=\033[92;4;1m
GREEN=\033[92;1m
YEL=\033[33m

all : MAKELIB MAKESERVER MAKECLIENT
	@echo "${UGREEN}COMPILATION FINISH\n"

MAKELIB :
	make -C $(PATH_TO_LIB)
	

MAKESERVER :
	make -C $(PATH_TO_SERVER)

MAKECLIENT :
	make -C $(PATH_TO_CLIENT)

clean :
	make clean -C $(PATH_TO_LIB)
	make clean -C $(PATH_TO_SERVER)
	make clean -C $(PATH_TO_CLIENT)
	@echo "${GREEN}CLEAN FINISH\n"

fclean : clean
	make fclean -C $(PATH_TO_LIB)
	make fclean -C $(PATH_TO_SERVER)
	make fclean -C $(PATH_TO_CLIENT)
	@echo "${GREEN}FCLEAN FINISH\n"

re : fclean all

.PHONY : all clean fclean re

.SILENT : 

