#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ntg)
{
    (void)ntg;
	static int	bit = 0;
	static int	i = 0;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
    else if (sig == SIGUSR2)
      i |= 0;
    bit++;
	    if (bit == 8)
	{        
		write(1, &i, 1);
		i = 0;
		bit = 0;
        kill(info->si_pid, SIGUSR1);
	}
}
int main(int ac, char **av)
{
    (void)av;
    int pid;
    struct sigaction sa;
    
    pid = getpid();
    if(ac == 1)
    {
        if (pid <= 0)
        {
            write(1, "Failure!!!!", 12);
            exit(1);
        }
        ft_printf(">>>>>>>>>>CONNECTED TO 42POTATO'S SERVER:D<<<<<<<<<<<\n");
        sleep(1);
        ft_printf("Process ID : %d\n", pid); 
        sleep(1);
        ft_printf("Type...\n");
        sa.sa_flags = SA_SIGINFO;
        sa.sa_sigaction = handler;
        while (1)
        {
            sigaction(SIGUSR1, &sa, NULL);
            sigaction(SIGUSR2, &sa, NULL);
            pause();
        }
    }
    else
    {
        write(1, "Error!\n", 8);
        exit(1);
    }
    return (0);
}