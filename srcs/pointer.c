/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:20:03 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:37:26 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	digit_ptr(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = va_arg(*ap, unsigned long int);
	if (tmp == 0 && list->out.ch_zero)
	{
		list->out.out = ft_strdup("");
		return (0);
	}
	list->out.out = ft_itoa_base((size_t)tmp, 16, 1);
	list->data.out_len = ft_strlen(list->out.out);
	if (list->flag.zero == 1 && list->data.prscn != 0)
		list->flag.zero = 0;
	list->data.width -= 2;
	set_width(list);
	set_precision(list);
	return (0);
}

int	print_ptr(t_lst *list)
{
	int res;

	res = 0;
	if (list->flag.zero == 1)
		res += ft_putstrs("0x");
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->flag.zero == 0)
		res += ft_putstrs("0x");
	if (list->data.prscn != 0)
		res += add_prcsn(list);
	res += (int)ft_putstrs(list->out.out);
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
