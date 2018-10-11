/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:18:29 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:35:23 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		lst_writer(t_lst *list, ssize_t *res, va_list *ap)
{
	while (list != NULL)
	{
		if (list->data.var == '0')
		{
			if (list->out.out != NULL)
				if (!(*res += ft_putstrs(list->out.out)))
					return (-1);
		}
		else
		{
			type_handler(list, ap);
			*res += print_type(list);
		}
		list = list->next;
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	t_lst	*list;
	ssize_t	res;

	va_start(ap, format);
	res = 0;
	if (format[0] == '\0')
		return (0);
	if (!(list = lst_init()))
		return (-1);
	process_format(format, list, &ap);
	if (lst_writer(list, &res, &ap) == -1)
		return (-1);
	va_end(ap);
	lst_free(&list);
	return ((int)res);
}
