/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:56:19 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/15 19:19:09 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_putendl_fd(char *s)
{
	int	count;

	count = 0;
	count += ft_putstr_fd(s);
	count += ft_putchar_fd('\n');
	return (count);
}
