/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:20:02 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/15 18:59:40 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			count;
	int			i;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += exe_flags(s[i + 1], ap);
		i++;
		}
		else
			count += ft_putchar_fd(s[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	exe_flags(const char a, va_list s)
{
	int	count;

	count = 0;
	if (a == 'c')
		count += ft_putchar_fd(va_arg(s, int));
	else if (a == 's')
		count += ft_putstr_fd(va_arg(s, char *));
	else if (a == 'p')
		count += void_to_hexa(va_arg(s, unsigned long long));
	else if (a == 'd' || a == 'i')
		count += ft_put_di(va_arg(s, int));
	else if (a == 'u')
		count += ft_put_u(va_arg(s, unsigned int));
	else if (a == 'x' || a == 'X')
		count += ft_print_hex(va_arg(s, unsigned int), a);
	else if (a == '%')
		count += put_x();
	return (count);
}
