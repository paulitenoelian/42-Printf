/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:19:52 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:37:07 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	percent(t_lst *list, va_list *ap)
{
	va_list b;

	va_copy(b, *ap);
	list->out.out = ft_strdup("%");
	list->data.prscn = 0;
	list->data.width -= 1;
	set_width(list);
	return (0);
}

int	print_percent(t_lst *list)
{
	int res;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	res += (int)ft_putstrs(list->out.out);
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}

int	error_input(t_lst *list, va_list *ap)
{
	va_list b;

	va_copy(b, *ap);
	list->data.width -= 2;
	set_width(list);
	return (0);
}

int	print_error(t_lst *list)
{
	int res;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	res += ft_putchars((unsigned int)list->data.error);
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
