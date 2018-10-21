/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:05:03 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/21 07:52:43 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ft_printf_unsigned(char **str, va_list *ap, t_p *p)
{
	uintmax_t u;

	(void)str;
	get_u(ap, p, &u);
	return (ft_putnbr_unsign(u, _DEC, p, NULL));
}
