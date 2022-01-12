#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

# include <stdio.h> // A SUPPRIMER 


char **str_to_byte(char *str);
void	send_str(char **str, pid_t pid);
void	send_char(char *c_bin, pid_t pid);
void	free_data(char **str);

#endif
