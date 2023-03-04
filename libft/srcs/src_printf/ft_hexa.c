/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:13:12 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/15 19:02:33 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	nb_to_hexa(unsigned int a, const char type)
{
	if (a >= 16)
	{
		nb_to_hexa((a / 16), type);
		nb_to_hexa((a % 16), type);
	}
	else
	{
		if (a <= 9)
			ft_putchar_fd(a + '0');
		else
		{
			if (type == 'x')
				ft_putchar_fd(a - 10 + 'a');
			else if (type == 'X')
				ft_putchar_fd(a - 10 + 'A');
		}
	}
	return (hexa_len(a));
}

int	hexa_len(unsigned int a)
{
	int	len;

	len = 0;
	while (a != 0)
	{
		len++;
		a = a / 16;
	}
	return (len);
}

int	ft_print_hex(unsigned int a, const char type)
{
	int	count;

	count = 0;
	if (a == 0)
		count += write(1, "0", 1);
	else
		count += nb_to_hexa(a, type);
	return (count);
}
