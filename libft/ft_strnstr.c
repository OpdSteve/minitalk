/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:01:52 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/26 19:03:46 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!(*little))
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while (big[i] == little[i] && i < len)
		{
			if (!(little[i + 1]))
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (NULL);
}
