/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:41:36 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/23 22:57:45 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"

/* This will be used fot broke the string in part of 8 bits, send the bit and
continue for the next 8 bits & print the letter when complete 8 bits. */
void	ft_signaller(int signal)
{
	static char	character;
	static int	bit;

	if (signal == SIGUSR2)
		character = character | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (character));
		bit = 0;
		character = 0;
	}
}

/* Get the PID of the proccess and print the PID. And wait por a signal for
*this PID proccess*/
int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("SERVER PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_signaller);
		signal(SIGUSR2, ft_signaller);
		pause();
	}
	return (0);
}
