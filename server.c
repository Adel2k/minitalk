#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ntg)
{
    (void)ntg;
    (void)info;
	static int	bit = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
    else if (sig == SIGUSR2)
      i |= 0;
    bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bit = 0;
        
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
            ft_printf("Failure!!!!");
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
        printf("Error!\n");
        exit(1);
    }
    return (0);
}