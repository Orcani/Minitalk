/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:48:59 by desambou          #+#    #+#             */
/*   Updated: 2025/02/10 14:08:07 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _GNU_SOURCE

# ifndef MAX_BUFFER_SIZE
#  define MAX_BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

size_t	ft_strlen(const char *s);
char	*ft_malloccpy(char const *dst, char const src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void handle_sig(int signum, siginfo_t *info, void *context);
char	*ft_strdup(const char *s);
int ft_atoi(const char *nptr);
void	sigbit(int signum, siginfo_t *info, void *context);
void	sigend(int signum, siginfo_t *info, void *context);
void	send_bit(pid_t pid, char *message);

#endif