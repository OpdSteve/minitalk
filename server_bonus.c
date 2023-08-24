/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go@student.42malaga.co <eleon-go>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:12:13 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/24 13:25:53 by eleon-go@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"

/* This will be used fot broke the character in part of 8 bits, send the bit and
*continue for the next 8 bits & print the letter when complete 8 bits.
*This is a little diferent than the normal server, because use signation
structure. Signal is SIGUSR2 (0/1) siginfo use for signations structure
and void *context is literally nathing, i don,t need to use*/
static void	ft_signaller(int signal, siginfo_t *info, void *context)
{
	static char	letter;
	static int	bit;

	(void) context;
	if (signal == SIGUSR2)
		letter = letter | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (letter));
		bit = 0;
		letter = 0;
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
