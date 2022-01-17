#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

# include <stdio.h> // A SUPPRIMER 

typedef struct s_data
{
	pid_t pid_client;
	int bits;
	char char_received;
	char* msg;
	int sig_received;
}	t_data;


void receive_char(int sig, siginfo_t *siginfo, void *context);


#endif
