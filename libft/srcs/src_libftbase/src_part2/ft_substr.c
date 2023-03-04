/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:36:55 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:07 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static char	*go(char const *s, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	a = malloc(len + 1);
	if (!a)
		return (NULL);
	while (i < len && s[i])
	{
		a[i] = (char) s[i];
		i++;
	}
	a[i] = 0;
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char	*p;

	if (start > ft_strlen (s))
		start = ft_strlen (s);
	if (start + n > ft_strlen (s))
		n = ft_strlen (s) - start;
	p = go(s + start, n);
	return (p);
}
