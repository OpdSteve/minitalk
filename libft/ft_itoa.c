/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:26:17 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/28 12:27:55 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(long int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count = 1;
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			count++;
		}
		while (nb > 0)
		{
			nb /= 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	i = ft_digit_count(nb);
	str = malloc(i * sizeof(char) + 1);
	if (!(str))
		return (0);
	str[i--] = 0;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
