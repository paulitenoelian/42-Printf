/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:20:17 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/08 19:20:18 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	print_type(t_lst *l)
{
	size_t res;

	res = 0;
	if (l->data.var == 'i' || l->data.var == 'd' || l->data.var == 'D')
		res += print_dec(l);
	if (l->data.var == 'x' || l->data.var == 'X')
		res += print_hex(l);
	if (l->data.var == 'u' || l->data.var == 'U')
		res += print_unsigned(l);
	if (l->data.var == 'o' || l->data.var == 'O')
		res += print_oct(l);
	if (l->data.var == 'p')
		res += print_ptr(l);
	if (l->data.var == '%')
		res += print_percent(l);
	if (l->data.var == 'C' || (l->data.var == 'c' && l->out.below_zero == 4))
		res += print_char_c(l);
	if (l->data.var == 'c' && l->out.below_zero == 0)
		res += print_char(l);
	if (l->data.var == 's' || l->data.var == 'S')
		res += print_char_string(l);
	if (l->data.var == 'w')
		res += print_error(l);
	return (res);
}
