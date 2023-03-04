/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:05:45 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:07 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	j = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0 || len_dest > size)
		return (size + len_src);
	while (src[j] != '\0' && (len_dest + j < size - 1))
	{
		dest[len_dest + j] = src[j];
		j++;
	}
	dest[len_dest + j] = '\0';
	return (len_dest + len_src);
}
