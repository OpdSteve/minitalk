/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:59:08 by eleon-go@st       #+#    #+#             */
/*   Updated: 2022/12/11 19:24:18 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c +32);
	return (c);
}

/*
int main(void)
{
	int c;
	c = 'b';
	printf ("Me sale %c\n", ft_toupper(c));
	return (0);
}
*/