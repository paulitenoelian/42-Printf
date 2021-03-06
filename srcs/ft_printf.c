/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:03:20 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/21 07:54:50 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print			ft_get_param(char c)
{
	static t_print *param = NULL;

	if (param == NULL)
	{
		if ((param = ft_memalloc(sizeof(*param) * 256)) != NULL)
		{
			param['%'] = &ft_printf_percent;
			param['i'] = &ft_printf_int;
			param['d'] = &ft_printf_int;
			param['D'] = &ft_printf_long;
			param['c'] = &ft_printf_char;
			param['C'] = &ft_printf_wchar;
			param['s'] = &ft_printf_str;
			param['S'] = &ft_printf_wstr;
			param['x'] = &ft_printf_hex;
			param['X'] = &ft_printf_hex;
			param['o'] = &ft_printf_octal;
			param['O'] = &ft_printf_long;
			param['u'] = &ft_printf_unsigned;
			param['U'] = &ft_printf_long;
			param['p'] = &ft_printf_void;
		}
	}
	return (param[(int)c]);
}

static int		is_str(char **str)
{
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+'
		|| **str == ' ')
		return (1);
	if (**str == '.' || **str == '*' || ft_isdigit(**str))
		return (1);
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
		return (1);
	return (0);
}

static ssize_t	ft_param(ssize_t s, t_p *p, char **str, va_list *ap)
{
	t_print	func;

	if ((*(++*str)) == '\0')
		return (0);
	p->size = '\0';
	while (is_str(str) == 1)
	{
		ft_check_flags(str, p);
		ft_check_width(str, p, ap);
		ft_check_precision(str, p, ap, 0);
		ft_check_size(str, p, '\0');
	}
	if (**str == '\0')
		return (0);
	if ((func = ft_get_param(**str)) == NULL)
		func = ft_null;
	s = func(str, ap, p);
	(*str)++;
	return (s);
}

static int		ft_solve(size_t s, va_list *ap, const char *str)
{
	char	*next;
	t_p		p;
	ssize_t	r;

	next = ft_strchr(str, '%');
	if (*str == '\0')
		return (s);
	if (next == NULL)
		return (s + write(1, str, ft_strlen(str)));
	else if (next > str)
		return (ft_solve(s + write(1, str, next - str), ap, next));
	else
	{
		ft_bzero(&p, sizeof(p));
		return ((r = ft_param(0, &p, (char **)&str, ap)) == -1 ? -1 :\
				ft_solve(s + r, ap, str));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;

	va_start(ap, format);
	n = ft_solve(0, &ap, format);
	va_end(ap);
	return (n);
}
