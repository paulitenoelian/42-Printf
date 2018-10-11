/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:12:37 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:32:46 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	char_c_c(t_lst *list, va_list *ap)
{
	va_list b;

	va_copy(b, *ap);
	list->data.var_type = va_arg(*ap, unsigned int);
	list->data.prscn = 0;
	list->data.width -= 1;
	set_width(list);
	return (0);
}

int	print_char_c(t_lst *list)
{
	int res;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->data.var_type == 0)
		res += write(1, "\0", 1);
	else
		res += (int)ft_putchars((unsigned)list->data.var_type);
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
