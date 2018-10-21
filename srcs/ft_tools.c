/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:05:28 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/21 07:53:04 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_min(int a, int b)
{
	return (_MIN(a, b));
}

int			ft_max(int a, int b)
{
	return (_MAX(a, b));
}

void		ft_space(int len, int width, char c)
{
	while (len < width--)
		write(1, &c, 1);
}

uintmax_t	ft_len(uintmax_t j, char *base)
{
	size_t		base_len;
	uintmax_t	j_len;

	base_len = ft_strlen(base);
	j_len = 0;
	if (j == 0)
		return (1);
	while (j)
	{
		j /= base_len;
		j_len++;
	}
	return (j_len);
}

uintmax_t	ft_len_j(uintmax_t j, char *base, char *front, t_p *p)
{
	uintmax_t j_len;
	uintmax_t jstr_len;

	j_len = ft_len(j, base);
	if (j == 0 && p->is_precision && p->precision == 0)
		jstr_len = 0;
	else
		jstr_len = p->is_precision ? ft_max(j_len, (uintmax_t)p->precision) :\
									j_len;
	if (p->hash && front && j != 0)
		jstr_len = jstr_len + ft_strlen(front);
	return (jstr_len);
}
