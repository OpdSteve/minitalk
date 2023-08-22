/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go@student.42malaga.co <eleon-go>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:41:36 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/22 14:48:50 by eleon-go@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"

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
