/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:20:41 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:37:39 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		str_add_param(t_lst *list)
{
	list->data.out_len = ft_strlen(list->out.out);
	if (list->data.out_len < list->data.prscn)
		list->data.prscn = 0;
	if (list->data.prscn > 0)
		list->data.out_len = list->data.prscn;
	if (list->data.out_len > list->data.width)
		list->data.width = list->data.width - list->data.out_len;
	set_width(list);
	if (list->data.width != 0 && list->data.out_len > list->data.prscn
		&& list->data.prscn != 0)
		list->data.width += list->data.out_len - list->data.prscn;
}

int				char_string(t_lst *list, va_list *ap)
{
	char *tmp;

	if (list->data.var_type == 4)
	{
		unicode_string(list, ap);
		return (0);
	}
	tmp = va_arg(*ap, char *);
	if (tmp == NULL && list->out.ch_zero == 0)
	{
		if (!(list->out.out = ft_strdup("(null)")))
			return (-1);
	}
	else
	{
		if (tmp == NULL || list->out.ch_zero == 1)
		{
			list->out.out = ft_strnew(0);
			return (0);
		}
		if (!(list->out.out = ft_strdup(tmp)))
			return (-1);
	}
	str_add_param(list);
	return (0);
}

int				unicode_string(t_lst *list, va_list *ap)
{
	unsigned int *str;

	str = va_arg(*ap, unsigned int *);
	if (str == NULL)
	{
		list->out.out = ft_strdup("(null)");
		return (0);
	}
	if (!(list->out.out = uni_proc(str, list->data.prscn, list->out.ch_zero)))
		return (-1);
	list->data.out_len = ft_strlen(list->out.out);
	if (list->data.out_len < list->data.prscn)
		list->data.prscn = 0;
	if (list->data.prscn > 0)
		list->data.out_len = list->data.prscn;
	if (list->data.out_len > list->data.width)
		list->data.width = list->data.width - list->data.out_len;
	set_width(list);
	if (list->data.width != 0 && list->data.out_len > list->data.prscn
		&& list->data.prscn != 0)
		list->data.width += list->data.out_len - list->data.prscn;
	return (0);
}

size_t			mini_writer(char *str, size_t n)
{
	size_t	i;
	size_t	res;
	int		tmp_n;

	tmp_n = n;
	i = 0;
	res = 0;
	while (i < n)
	{
		res += write(1, &str[i], 1);
		i++;
	}
	return (res);
}

int				print_char_string(t_lst *list)
{
	int res;

	res = 0;
	if (list->data.width != 0 && list->flag.minus == 0)
		res += add_width(list);
	if (list->data.out_len >= list->data.prscn && list->data.prscn != 0)
		res += mini_writer(list->out.out, list->data.prscn);
	else
		res += (int)ft_putstrs(list->out.out);
	if (list->data.width != 0 && list->flag.minus == 1)
		res += add_width(list);
	return (res);
}
