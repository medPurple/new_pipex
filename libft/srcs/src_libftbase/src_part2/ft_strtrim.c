/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:49:18 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:07 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static int	is_sep(char *sep, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(sep))
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	long	i;
	char	*p;

	while (is_sep((char *)set, *s))
		s++;
	i = ft_strlen(s);
	while (i > 0 && is_sep((char *)set, s[i - 1]))
		i--;
	p = ft_substr(s, 0, i);
	return (p);
}
