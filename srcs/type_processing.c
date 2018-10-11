/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:20:49 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/08 19:20:51 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		fill_sample(int (**f)(t_lst *, va_list *))
{
	f[0] = &char_string;
	f[1] = &unicode_string;
	f[2] = &digit_ptr;
	f[3] = &digit_dec;
	f[4] = &digit_dec;
	f[5] = &digit_dec;
	f[6] = &digit_oct;
	f[7] = &digit_oct;
	f[8] = &digit_unsigned;
	f[9] = &digit_unsigned;
	f[10] = &digit_hex;
	f[11] = &digit_hex;
	f[12] = &char_c;
	f[13] = &char_c_c;
	f[14] = &percent;
	f[15] = &error_input;
}

int				type_handler(t_lst *list, va_list *ap)
{
	int		i;
	char	*sample;
	int		(*f[16])(t_lst *, va_list *);

	i = 0;
	fill_sample(f);
	sample = "sSpdDioOuUxXcC%w";
	while (sample[i] != '\0')
	{
		if (sample[i] == list->data.var)
			break ;
		i++;
		if (sample[i] == '\0')
			return (0);
	}
	f[i](list, ap);
	return (0);
}
