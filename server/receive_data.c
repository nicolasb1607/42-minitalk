#include "./includes/server.h"

void receive_char(int sig, siginfo_t *siginfo, void *context)
{
    static char current = 0;
    static int i;
    (void) context;
    
    if (sig == SIGUSR1 && i < 8)
    {
        current |= (1 << (7 - i++));
        kill(siginfo->si_pid, SIGUSR1);
    }
    if (sig == SIGUSR2 && i < 8)
    {
        current &= ~(1 << (7 - i++));
        kill(siginfo->si_pid, SIGUSR1);
    }
    //printf("value of i = %d\n", i);
    if (i == 8)
    {   
        if (current == 0)
            ft_putchar('\n');
        else
            ft_putchar(current);
        i = 0;
    }
}

