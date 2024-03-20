#include "minitalk.h"
#include <string.h>
#include "ft_printf/ft_printf.h"
/*void    handler(int sig)
{
        char        result[8] = {'\0'};
        static int  i = 0;
        if (sig == SIGUSR1)
        {
            result[i] = '1';
            printf("%c", result[i]);
            i++;
        }
        else if (sig == SIGUSR2)
        {
            result[i] = '0';
            printf("%c", result[i]);
            i++;
        }
       
        else if (i == 8)
        {
            // int res = 0;
            // int j = 0;
            // ft_printf("%s\n", result);
            // while (j < 8)
            // {
            //     ft_printf("%c", result[i]);
            //     res |= result[j];
            //     j++;
            //     if (j != 8)
            //         res <<= 1;
            // }
            ft_printf("%s\n",result);
            write(1, "\n", 1);
            i = 0;

        }
}
*/

void	handler(int sig)
{
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
int main()
{   
    int pid;
    pid = getpid();
    if (pid <= 0)
    {
        printf("Failure!!!!");
        exit(1);
    }
    printf("PID : %d\n", pid); 
    struct sigaction sa;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = handler;
    
    while (1)
    {
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        pause();
    }



    return (0);
}