#include "./includes/client.h"

void handler()
{
	write(1, "received", 8);
}

void	send_bit(char c, pid_t pid)
{
	if (c == '1')
		kill(pid, SIGUSR1);
	if (c == '0')
		kill(pid, SIGUSR2);
}

void	send_char(char *c_bin, pid_t pid)
{
	int i;

	i = 0;
	while(i < 8)
	{
		send_bit(c_bin[i++], pid);
		signal(SIGUSR1,handler);
		//usleep(100);
	}
}

void	send_str(char **str, pid_t pid)
{
	int i;

	i = 0;
	while (str[i])
		send_char(str[i++], pid);
	//send_char('\0', pid);
}