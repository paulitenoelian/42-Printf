/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:04:09 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/21 07:50:54 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ft_putnbr_front(uintmax_t j, char *base, t_p *p, char front)
{
	uintmax_t		j_len;
	uintmax_t		front_len;

	front_len = front != '\0' ? 1 : 0;
	j_len = ft_len_j(j, base, NULL, p) + front_len;
	if (p->is_width && !p->minus && !p->zero)
	{
		ft_space(j_len, p->width, ' ');
		front_len += _MAX(p->width - (int)j_len, 0);
		p->is_width = 0;
	}
	else if (p->is_width)
		p->width -= front_len;
	if (front_len)
		write(1, &front, 1);
	return (ft_putnbr_unsign(j, base, p, NULL) + front_len);
}

intmax_t	ft_putnbr_unsign(uintmax_t j, char *base, t_p *p, char *front)
{
	uintmax_t	j_len;
	uintmax_t	jstr_len;

	p->zero = p->precision ? 0 : p->zero;
	j_len = ft_len(j, base);
	if (p->is_width && !p->minus && p->zero)
	{
		p->precision = p->is_precision ? ft_max(p->width, p->precision) :\
										ft_max(p->width, j_len);
		p->is_precision = 1;
		p->is_width = 0;
		p->precision -= p->hash && front && j != 0 ? ft_strlen(front) : 0;
	}
	jstr_len = ft_len_j(j, base, front, p);
	if (p->is_width && !p->minus)
		ft_space(jstr_len, p->width, ' ');
	if (p->hash && front != NULL && j != 0)
		write(1, front, ft_strlen(front));
	p->is_precision ? ft_space(j_len, p->precision, '0') : 0;
	j == 0 && p->is_precision && p->precision == 0 ? 0 :\
											ft_putnbr_u_base_fd(j, base, 1);
	if (p->is_width && p->minus)
		ft_space(jstr_len, p->width, ' ');
	return (p->is_width ? ft_max(jstr_len, p->width) : jstr_len);
}

static void	get_i(intmax_t *i, va_list *ap, t_p *p)
{
	*i = va_arg(*ap, intmax_t);
	if (p->size == 'H')
		*i = (char)*i;
	else if (p->size == 'h')
		*i = (short int)*i;
	else if (p->size == 'l')
		*i = (long int)*i;
	else if (p->size == 'L')
		*i = (long long int)*i;
	else if (p->size == 'j')
		*i = (intmax_t)*i;
	else if (p->size == 'z')
		*i = (size_t)*i;
	else
		*i = (int)*i;
}

intmax_t	ft_printf_int(char **str, va_list *ap, t_p *p)
{
	intmax_t	i;
	uintmax_t	j;
	char		front;

	(void)str;
	if (p->is_precision)
		p->zero = 0;
	get_i(&i, ap, p);
	j = _ABS(i);
	if (i < 0 || p->plus || p->space)
	{
		if (i < 0)
			front = '-';
		else if (p->plus)
			front = '+';
		else if (p->space)
			front = ' ';
		else
			front = '\0';
		return (ft_putnbr_front(j, _DEC, p, front));
	}
	return (ft_putnbr_unsign(j, _DEC, p, NULL));
}
