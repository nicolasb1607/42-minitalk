#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

# include <stdio.h> // A SUPPRIMER 

void    send_str(char *str, pid_t pid);

#endif
