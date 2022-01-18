CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = server
LIB = libft.a
PATH_TO_LIB = ../libft/

SRCS = ./main.c

INCLUDES = ./includes/

OBJS = ${SRCS:.c=.o}

all : EXEC

EXEC : OBJS
	$(CC) $(CFLAGS) -L $(PATH_TO_LIB) $^ -I $(INCLUDES) -lft -o $(EXEC)

.o : .c
	make -C $(PATH_TO_LIB)
	$(CC) $(CFLAGS) -c -L $(PATH_TO_LIB) $< -o $@ -I $(INCLUDES) -lft

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(EXEC)





