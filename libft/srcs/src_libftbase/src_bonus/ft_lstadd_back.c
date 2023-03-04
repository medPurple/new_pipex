/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:47:25 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/15 11:38:50 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *list)
{
	t_list	*p;

	if (!*lst)
		*lst = list;
	else
	{
		p = ft_lstlast(*lst);
		p->next = list;
	}
}
