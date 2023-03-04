/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:56:32 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:08 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*p;

	p = s1;
	if (n == 0 && (!(s1 && s2)))
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (*p && n)
	{	
		if (ft_memcmp(p, s2, ft_strlen(s2)) == 0 && ft_strlen(s2) <= n)
			return ((char *)p);
		p++;
		n--;
	}
	return (NULL);
}
