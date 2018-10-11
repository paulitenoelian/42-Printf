/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:18:52 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:35:55 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t		get_res(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = 0;
	if (list->data.var_type == 0)
		tmp = (size_t)va_arg(*ap, unsigned int);
	if (list->data.var_type == 3)
		tmp = (size_t)((unsigned short)va_arg(*ap, unsigned int));
	if (list->data.var_type == 4)
		tmp = (size_t)va_arg(*ap, unsigned long int);
	if (list->data.var_type == 1)
		tmp = (size_t)((unsigned char)va_arg(*ap, unsigned int));
	if (list->data.var_type == 2)
		tmp = (size_t)va_arg(*ap, unsigned long long int);
	if (list->data.var_type == 5)
		tmp = (size_t)(size_t)va_arg(*ap, uintmax_t);
	if (list->data.var_type == 6)
		tmp = (size_t)va_arg(*ap, size_t);
	return (tmp);
}

static void			from_x_to_lx(t_lst *list)
{
	size_t i;

	i = 0;
	while (list->out.out[i] != '\0')
	{
		list->out.out[i] = (char)ft_toupper(list->out.out[i]);
		i++;
	}
}

int					digit_hex(t_lst *list, va_list *ap)
{
	size_t tmp;

	tmp = get_res(list, ap);
	if (tmp == 0 && list->out.ch_zero)
	{
		list->out.out = ft_strdup("");
		list->flag.hash = 0;
		return (0);
	}
	list->out.out = ft_itoa_base((size_t)tmp, 16, 1);
	list->data.out_len = ft_strlen(list->out.out);
	if (list->flag.zero == 1 && list->data.prscn != 0)
		list->flag.zero = 0;
	if (list->flag.hash == 1)
		list->data.width -= 2;
	if (list->data.var == 'X')
		from_x_to_lx(list);
	set_width(list);
	set_precision(list);
	return (0);
}

int					print_hex(t_lst *list)
{
	int res;

	res = 0;
	if (list->flag.zero == 1 && list->flag.hash == 1
		&& list->data.var == 'x' && list->out.out[0] != '0')
		res += ft_putstrs("0x");
	if (list->flag.zero == 1 && list->flag.hash == 1
		&& list->data.var == 'X' && list->out.out[0] != '0')
		res += ft_putstrs("0X");
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->flag.hash == 1 && list->flag.zero == 0
		&& list->data.var == 'x' && list->out.out[0] != '0')
		res += ft_putstrs("0x");
	if (list->flag.hash == 1 && list->flag.zero == 0
		&& list->data.var == 'X' && list->out.out[0] != '0')
		res += ft_putstrs("0X");
	if (list->data.prscn != 0)
		res += add_prcsn(list);
	res += (int)ft_putstrs(list->out.out);
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
