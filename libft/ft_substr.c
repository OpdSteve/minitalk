/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:46:14 by eleon-go          #+#    #+#             */
/*   Updated: 2023/01/28 12:48:36 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	int				leng;
	char			*mal;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		leng = ft_strlen(s) - start;
	else
		leng = len;
	mal = malloc(sizeof(char) * leng + 1);
	if (!mal)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && i <= ft_strlen(s))
	{
		if (i >= start && j < len)
			mal[j++] = s[i];
		i++;
	}
	mal[j] = '\0';
	return (mal);
}
