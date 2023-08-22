/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go@student.42malaga.co <eleon-go>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:40:56 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/22 14:48:17 by eleon-go@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"

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
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments. Need ./client <PID> <Message>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		ft_send_bit(pid, str);
	}
	ft_send_bit(pid, "\n");
	return (0);
}
