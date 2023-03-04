/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmessmer <wmessmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:29:25 by wmessmer          #+#    #+#             */
/*   Updated: 2022/12/14 14:42:07 by wmessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*tmp;
	void	*content;

	if (!f)
		return (NULL);
	p = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			if (del)
				(*del)(content);
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, tmp);
		lst = lst->next;
	}
	return (p);
}
