/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:11:37 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/26 19:13:18 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32) && nptr[i])
	{
		i++;
	}
	if ('+' == nptr[i] || '-' == nptr[i])
	{
		if ('-' == nptr[i])
			sign = -1;
		i++;
	}
	while ('0' <= nptr[i] && '9' >= nptr[i])
	{
		res = res * 10 + ((nptr[i] - '0'));
		i++;
	}
	return (sign * (res));
}
