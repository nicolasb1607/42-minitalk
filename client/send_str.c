#include "./includes/client.h"

void end_msg(pid_t pid)
{
	int i;

	while (i < 8)
	{
		kill(pid, SIGUSR2);
		pause();
		i++;
	}
}

void send_str(char *str, pid_t pid)
{
	int i;
	int j;
	int mask;
	int sig;

	i = 0;
	while (str[i])
	{
		mask = (1 << 7);
		j = 0;
		while (j < 8)
		{
			sig = str[i] & mask;
			if (sig)
				kill(pid, SIGUSR1);
			else if (sig == 0)
				kill(pid, SIGUSR2);
			mask = (mask >> 1);
			pause();
			j++;
		}
		i++;
	}
	end_msg(pid);
}