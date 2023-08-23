/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:11:45 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/23 23:18:34 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"


static void	ft_signal_back(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("");
	if (signal == SIGUSR1)
		ft_printf("");
}

/*Use the PID proccess and a signal for send the string in form of bits.Then
use SIGNUR2 to send 1 and 0, use Kill to send the bit for SIGNUR2. If is 
diferent,send the signal in SIGNUR1 and wait 100 ms during the proccess to 
not crash 1 letter of the string use 8 bits, when send 8 bits, use str++ to 
continue for the string until the end*/
static void	ft_send_bit(int pid, char *str)
{
	int		bit;
	char	character;

	while (*str)
	{
		bit = 8;
		character = *str;
		while (bit--)
		{
			if (character >> bit & 1)
				kill (pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int			pid;
	char		*str;

	if (argc != 3)
	{
		ft_printf("Put all things in order: ./client <PID> <Message>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		signal(SIGUSR1, ft_signal_back);
		signal(SIGUSR2, ft_signal_back);
		ft_send_bit(pid, str);
	}
	ft_send_bit(pid, "\n");
	return (0);
}
