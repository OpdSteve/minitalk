/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon-go <eleon-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:35:04 by eleon-go@st       #+#    #+#             */
/*   Updated: 2022/12/14 20:47:58 by eleon-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c -32);
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