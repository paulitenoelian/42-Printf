/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:02:01 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/21 07:50:07 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ft_null(char **str, va_list *ap, t_p *p)
{
	(void)ap;
	if (p->is_width && !p->minus)
		ft_space(1, p->width, p->zero ? '0' : ' ');
	write(1, *str, 1);
	if (p->is_width && p->minus)
		ft_space(1, p->width, ' ');
	return (p->is_width ? ft_max(p->width, 1) : 1);
}
