/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go@student.42malaga.co <eleon-go>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:40:56 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/24 13:26:58 by eleon-go@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minitalk.h"

/*Use the PID proccess and a signal for send the string in form of bits. Then
*use SIGNUR2 to send 1, use Kill to send the bit for SIGNUR. If is diferent,
*send the signal in SIGNUR1 and wait 100 ms during the proccess to not crash
*1 letter of the string use 8 bits, when send 8 bits, use str++ to continue
*for the string until the end*/
static void	ft_send_bit(int pid, char *str)
{
	int		bit;
	char	letter;

	while (*str)
	{
		bit = 8;
		letter = *str;
		while (bit--)
		{
			if (letter >> bit & 1)
				kill (pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		str++;
	}
}

/*This main use two argument, the first is the PID number proccess, this use
*atoi to brake the PID and use it. The second argument is the text that we
*would like to send, that is the second string. If you trie to use the client
*with out the correct order, the program send a error mensage and close.
*If all are OK, use the send_bit for send the signal to the server funtions*/
int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Put all things in order: ./client <PID> <Message>\n");
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
