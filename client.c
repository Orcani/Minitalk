/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:48:38 by desambou          #+#    #+#             */
/*   Updated: 2025/02/10 16:14:54 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

int	g_g = 1;

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
void	sigbit(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		g_g = 1;
}

void	sigend(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR2)
	{
		ft_printf("Message received from: %d\n", info->si_pid);
		exit(0);
	}
}
void encrypt_bits(char c, pid_t pid)
{
    int bit;
    bit = 7;
   
    while (bit >= 0)
    {
        if ((c >> bit) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        bit--;
        usleep(200);
        while (g_g == 0)
            pause();
        g_g = 0;
    }
}
void message_s(char *message, pid_t pid)
{
    int i;
    i = 0;
    while (message[i] != '\0')
    {
        encrypt_bits(message[i], pid);
        i++;
    }
    encrypt_bits('\0', pid);
}

int main (int ac, char *av[])
{
    struct sigaction	s_1;
	struct sigaction	s_2;
    pid_t pid;
    char *message;

    if (ac != 3)
    {
        ft_printf("Oups, le format accepté est comme le suivant ./client [PID server] [message].");
        return (1);
    }
    pid = (pid_t)ft_atoi(av[1]);
    message = av[2];

    s_1.sa_sigaction = sigbit;
	s_2.sa_sigaction = sigend;
	sigemptyset(&s_1.sa_mask);
	sigemptyset(&s_2.sa_mask);
	s_1.sa_flags = SA_SIGINFO;
	s_2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1,&s_1, NULL);
    sigaction(SIGUSR2,&s_2, NULL);

	ft_printf("Sending message to PID: %d\n", pid);
	message_s(message, pid);
    // pause();
	return (0);
}
