/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:04:21 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/13 13:34:00 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ft_printf_long(char **str, va_list *ap, t_p *p)
{
	p->size = 'l';
	return (ft_get_param(ft_tolower(**str))(str, ap, p));
}
