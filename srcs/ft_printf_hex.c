/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:03:57 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/21 07:50:40 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		get_u(va_list *ap, t_p *p, uintmax_t *nbr)
{
	*nbr = va_arg(*ap, uintmax_t);
	if (p->size == 'H')
		*nbr = (unsigned char)*nbr;
	else if (p->size == 'h')
		*nbr = (unsigned short int)*nbr;
	else if (p->size == 'l')
		*nbr = (unsigned long int)*nbr;
	else if (p->size == 'L')
		*nbr = (unsigned long long int)*nbr;
	else if (p->size == 'j')
		*nbr = (uintmax_t)*nbr;
	else if (p->size == 'z')
		*nbr = (size_t)*nbr;
	else
		*nbr = (unsigned int)*nbr;
}

intmax_t	ft_printf_hex(char **str, va_list *ap, t_p *p)
{
	uintmax_t u;

	get_u(ap, p, &u);
	return (**str == 'X' ? ft_putnbr_unsign(u, _HEXU, p, "0X") :\
				ft_putnbr_unsign(u, _HEXL, p, "0x"));
}
