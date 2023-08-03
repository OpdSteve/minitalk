/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:48:28 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/28 12:11:47 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	x;

	ret = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	x = 0;
	while (x < ft_strlen(s1))
		ret[i++] = s1[x++];
	x = 0;
	while (x < ft_strlen(s2))
		ret[i++] = s2[x++];
	return (ret);
}
