/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:02:49 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/23 14:05:56 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstrev(t_list *alst)
{
	t_list	*prev;
	t_list	*list;
	t_list	*next;

	prev = NULL;
	list = alst;
	while (list != NULL)
	{
		next = list->next;
		list->next = prev;
		prev = list;
		list = next;
	}
	alst = prev;
	return (alst);
}
