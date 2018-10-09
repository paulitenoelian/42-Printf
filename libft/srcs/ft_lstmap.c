/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:34:18 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/23 12:20:24 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;
	t_list	*start;

	if (!lst)
		return (NULL);
	list = f(lst);
	new = ft_lstnew(list->content, list->content_size);
	if (!new)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		list = f(lst);
		new->next = ft_lstnew(list->content, list->content_size);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
