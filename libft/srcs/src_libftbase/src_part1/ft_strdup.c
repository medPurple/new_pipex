/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:41:44 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:07 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;
	int		len;

	len = ft_strlen((char *)src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
