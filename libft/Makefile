# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 16:22:42 by nburat-d          #+#    #+#              #
#    Updated: 2022/01/18 16:22:43 by nburat-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = libft.a
SRCS = ./ft_atoi.c \
	./ft_bzero.c \
	./ft_calloc.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isascii.c \
	./ft_isdigit.c \
	./ft_isprint.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memset.c \
	./ft_memmove.c \
	./ft_strchr.c \
	./ft_strdup.c \
	./ft_strlcat.c \
	./ft_strlcpy.c \
	./ft_strlen.c \
	./ft_strncmp.c \
	./ft_strnstr.c \
	./ft_strrchr.c \
	./ft_tolower.c \
	./ft_toupper.c \
	./ft_substr.c \
	./ft_strjoin.c \
	./ft_strtrim.c \
	./ft_split.c \
	./ft_itoa.c \
	./ft_striteri.c \
	./ft_strmapi.c \
	./ft_putchar_fd.c \
	./ft_putstr_fd.c \
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c \
	./ft_putchar.c \
	./ft_putstr.c \
	./ft_putnbr.c \
	./ft_lstnew.c \
	./ft_lstadd_front.c \
	./ft_lstsize.c \
	./ft_lstlast.c \
	./ft_lstadd_back.c \
	./ft_lstdelone.c \
	./ft_lstclear.c \
	./ft_lstiter.c \
	./ft_lstmap.c

INCLUDES = ./
OBJS_SRCS = ${SRCS:.c=.o}

BLUE=\033[34m
YEL=\033[33m


all : $(EXEC)
	@echo "$(BLUE)Compilation Libft DONE\n"

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)
 

$(EXEC) : $(OBJS_SRCS)
	ar rcs $(EXEC) $(OBJS_SRCS)

clean :
	rm -f $(OBJS_SRCS)
	@echo "$(YEL)Libft clean DONE\n"

fclean : clean
	rm -f $(EXEC)
	@echo "$(YEL)Libft fclean DONE\n"

re : fclean all

.PHONY : clean fclean re

.SILENT :