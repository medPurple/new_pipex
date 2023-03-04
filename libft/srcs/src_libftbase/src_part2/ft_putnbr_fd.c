/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:59:26 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/15 19:18:24 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_putnbr_fd(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar_fd('-');
		count += ft_putchar_fd('2');
		count += ft_putnbr_fd(147483648);
	}
	else if (n < 0)
	{
		count += ft_putchar_fd('-');
		count += ft_putnbr_fd(n * -1);
	}
	else if (n < 10)
		count += ft_putchar_fd((char)(n + '0'));
	else
	{
		count += ft_putnbr_fd(n / 10);
		count += ft_putchar_fd(n % 10 + '0');
	}
	return (count);
}
