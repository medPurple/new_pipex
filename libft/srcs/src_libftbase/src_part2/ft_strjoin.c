/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:15:36 by wmessmer          #+#    #+#             */
/*   Updated: 2023/01/13 18:21:34 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	tab = malloc (sizeof(char) * (size + 1));
	new = tab;
	if (!new)
	{
		free(tab);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
		tab[i++] = *s2++;
	tab[size] = '\0';
	free (s1);
	return (new);
}
