/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:20:53 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/28 12:23:10 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len_s;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_s = ft_strlen((const char *)s1);
	while (ft_strchr(set, *(s1 + len_s - 1)) && len_s > 0)
		len_s--;
	dest = ft_substr(s1, 0, len_s);
	return (dest);
}
