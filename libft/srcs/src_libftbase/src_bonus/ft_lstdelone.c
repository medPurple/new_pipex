/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:03:16 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:07 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
