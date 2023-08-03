/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:46:41 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/26 18:49:11 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pts;
	size_t			i;
	unsigned char	c_char;

	c_char = (unsigned char)c;
	pts = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (pts[i] == c_char)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
