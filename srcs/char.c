/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:12:17 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:32:06 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	char_c(t_lst *list, va_list *ap)
{
	if (list->data.var_type == 4)
	{
		list->out.below_zero = (int)list->data.var_type;
		char_c_c(list, ap);
		return (0);
	}
	list->out.out = ft_strnew(1);
	list->out.out[0] = (char)va_arg(*ap, int);
	list->data.prscn = 0;
	list->data.width -= 1;
	set_width(list);
	return (0);
}

int	print_char(t_lst *list)
{
	int res;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->out.out[0] == 0)
		res += write(1, "\0", 1);
	else
		res += (int)ft_putstrs(list->out.out);
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
