/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:07:24 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/23 14:08:44 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*tmp;
	t_list	*begin;

	tmp = *alst;
	begin = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	*alst = begin;
}
