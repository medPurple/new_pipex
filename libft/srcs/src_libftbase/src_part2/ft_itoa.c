/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:40:53 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/15 19:13:51 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

size_t	nblen(int n)
{
	size_t			i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	if (n < 0)
	{
		i++;
		nb = n * -1;
	}
	else
		nb = n;
	while (nb != 0 || i == 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*s;
	size_t	j;
	long	nb;

	j = (nblen(n));
	nb = n;
	s = malloc(j + 1);
	if (!(s))
		return (0);
	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		nb *= -1;
	}
	s[j] = 0;
	while (j > i)
	{
		s[--j] = nb % 10 + '0';
		nb /= 10;
	}
	return (s);
}
