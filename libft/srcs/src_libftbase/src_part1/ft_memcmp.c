/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:31:38 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:08 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size )
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	if (p1 == p2 || size == 0)
		return (0);
	s1 = (const unsigned char *)p1;
	s2 = (const unsigned char *)p2;
	while (size--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (size)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
