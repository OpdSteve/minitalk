/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go@student.42malaga.co <eleon-go>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:01:18 by eleon-go@st       #+#    #+#             */
/*   Updated: 2023/08/03 16:17:59 by eleon-go@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(long num)
{
	int		x;

	x = 0;
	if (num < 0)
	{
		x += ft_putchar('-');
		x += ft_putnbr(-num);
	}
	else if (num > 9)
	{
		x += ft_putnbr(num / 10);
		x += ft_putnbr(num % 10);
	}
	else
		x += ft_putchar(num + '0');
	return (x);
}

int	ft_unsigned_int(unsigned int long num)
{
	int	x;

	x = 0;
	if (num >= 10)
	{
		x += ft_unsigned_int(num / 10);
		x += ft_putchar("0123456789"[num % 10]);
	}
	else
		x += ft_putchar("0123456789"[num % 10]);
	return (x);
}

int	ft_putstr(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[x])
	{
		ft_putchar(str[x]);
		x++;
	}
	return (x);
}
