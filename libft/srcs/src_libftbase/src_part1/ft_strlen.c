/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:31:08 by wmessmer          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:00 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str && str[c])
		c++;
	return (c);
}
