/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:55:13 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/26 17:56:23 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		leng_s;
	char	*pts;

	leng_s = ft_strlen((const char *)(s));
	pts = (char *)(s + leng_s);
	while ((leng_s > 0) && *pts != (char)c)
	{
		pts--;
		leng_s--;
	}
	if (*pts == (char)c)
		return (pts);
	return (NULL);
}
