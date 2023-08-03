/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:46:49 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/26 17:48:40 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pts;

	pts = (char *)(s);
	while (*pts)
	{
		if (*pts == (char)c)
			return (pts);
		pts++;
	}
	if (!(char)c)
		return (pts);
	return (NULL);
}
