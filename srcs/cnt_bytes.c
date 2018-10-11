/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnt_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:13:06 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/08 19:13:08 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		count_bits(unsigned int c)
{
	int i;
	int tmp;

	i = 1;
	tmp = 0;
	while (i != 33)
	{
		if ((c & 1) == 1)
			tmp = i;
		c = c >> 1;
		i++;
	}
	return (tmp);
}

int		count_bytes(unsigned int c)
{
	int i;
	int tmp;

	i = 1;
	tmp = 0;
	while (i != 33)
	{
		if ((c & 1) == 1)
			tmp = i;
		c = c >> 1;
		i++;
	}
	if (tmp <= 7)
		return (1);
	else if (tmp <= 11)
		return (2);
	else if (tmp <= 16)
		return (3);
	else
		return (4);
	return (0);
}
