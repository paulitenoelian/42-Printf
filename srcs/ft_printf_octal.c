/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:38:18 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/13 13:39:55 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ft_printf_octal(char **str, va_list *ap, t_p *p)
{
	uintmax_t u;

	(void)str;
	get_u(ap, p, &u);
	if (p->hash && u == 0 && p->is_precision && p->precision == 0)
	{
		if (p->is_width && !p->minus)
			ft_space(1, p->width, p->zero ? '0' : ' ');
		write(1, "0", 1);
		if (p->is_width && p->minus)
			ft_space(1, p->width, ' ');
		return (p->is_width ? ft_max(p->width, 1) : 1);
	}
	if (p->hash && u != 0)
	{
		p->is_precision = 1;
		p->precision = _MAX(p->precision, (int)(ft_len(u, _OCT) + 1));
	}
	return (ft_putnbr_unsign(u, _OCT, p, NULL));
}
