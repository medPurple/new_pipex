/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:36:54 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/15 18:59:40 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_put_di(unsigned int i)
{
	int		k;
	char	*d;

	d = ft_itoa(i);
	k = ft_putstr_fd(d);
	free(d);
	return (k);
}

int	put_x(void)
{
	ft_putchar_fd('%');
	return (1);
}

int	ft_put_u(unsigned int i)
{
	int		count;
	char	*u;

	count = 0;
	if (i == 0)
		count += write(1, "0", 1);
	else
	{
		u = ft_unsigned_itoa(i);
		count += ft_putstr_fd(u);
		free(u);
	}
	return (count);
}

char	*ft_unsigned_itoa(unsigned int i)
{
	int		count;
	char	*u;

	count = ft_len_u(i);
	u = malloc(count + 1);
	if (!u)
		return (NULL);
	u[ft_len_u(i)] = '\0';
	while (i > 0)
	{
		u[count - 1] = i % 10 + 48;
		i /= 10;
		count--;
	}
	return (u);
}

int	ft_len_u(unsigned int u)
{
	int	count;

	count = 0;
	while (u != 0)
	{
		count++;
		u /= 10;
	}
	return (count);
}
