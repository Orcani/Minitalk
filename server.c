/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:48:34 by desambou          #+#    #+#             */
/*   Updated: 2025/02/10 16:15:30 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	char	*target;

	target = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (target == NULL)
		return (NULL);
	ft_strlcpy(target, s, ft_strlen(s) + 1);
	return (target);
}


char *string(char *message, char letter)
{
    int i;
    int j;
    char *tab;

   i = 0;
   while (message[i])
        i++;
   
   tab = malloc((i + 2) * sizeof(char));
   if (!tab)
        return (NULL);
    j = 0;
    while (j < i)
    {
        tab[j] = message[j];
        j++;
    }
    tab[i] = letter;
    tab[i + 1] = '\0';
    free(message);
    return (tab);
}
void decrypt_sig(int signum, siginfo_t *info, void *context)
{
    (void)context;
    static int bit = 0;
    static int byte = 0;
    static char *result = NULL;

    if(!result)
        result = ft_strdup("");
    if (signum == SIGUSR1)
       byte |= (1 <<(7 - bit));
    bit++;
    if (bit == 8)
    {        
        if (byte == '\0')
        {
            ft_printf("%s\n", result);
            kill(info->si_pid, SIGUSR2);
            free(result);
            result = NULL;
        }
        else
            result = string(result, byte);
        bit = 0;
        byte = 0;
    }
    kill(info->si_pid, SIGUSR1);
}
int main(void)
{ 
    struct sigaction sa;

    ft_printf("Welcome to Orca Server!\n");
    ft_printf("Server's PID: %d\n", getpid());
    ft_printf("Received message:\n");

    sa.sa_sigaction = decrypt_sig;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
    {
        pause();
    }
    return (0);
}
