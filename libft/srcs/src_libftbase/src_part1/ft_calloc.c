/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:18:25 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:08 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	buff = malloc(count * size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, count * size);
	return (buff);
}
