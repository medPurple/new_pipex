/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexavoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:39:55 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/15 18:59:40 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	void_to_hexa(unsigned long long p)
{
	int	count;

	count = 0;
	if (p == 0)
		count += write(1, "(nil)", 5);
	else
	{	
		count = write(1, "0x", 2);
		ft_print_hexavoid(p);
		count += hexavoid_len(p);
	}
	return (count);
}

void	ft_print_hexavoid(uintptr_t a)
{
	if (a >= 16)
	{
		ft_print_hexavoid(a / 16);
		ft_print_hexavoid(a % 16);
	}
	else
	{
		if (a <= 9)
			ft_putchar_fd(a + '0');
		else
			ft_putchar_fd(a - 10 + 'a');
	}
}

int	hexavoid_len(uintptr_t a)
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
