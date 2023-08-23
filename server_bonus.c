/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go@student.42malaga.co <eleon-go>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:12:13 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/23 14:30:29 by eleon-go@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"

static void	ft_signaller(int signal, siginfo_t *info, void *context)
{
	static char	caracter;
	static int	bit;

	(void) context;
	if (signal == SIGUSR2)
		caracter = caracter | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (caracter));
		bit = 0;
		caracter = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	info;

	pid = getpid();
	ft_printf("PID SERVER: %d\n", pid);
	info.sa_sigaction = ft_signaller;
	sigemptyset(&info.sa_mask);
	info.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &info, NULL);
		sigaction(SIGUSR2, &info, NULL);
		pause();
	}
	return (0);
}
