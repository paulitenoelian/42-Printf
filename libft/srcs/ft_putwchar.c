/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:26:43 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/05 07:26:44 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write(wchar_t c, int mask, int left, int right)
{
	unsigned int nbr;

	nbr = ((unsigned int)c << left >> right) | mask;
	write(1, &nbr, 1);
}

void		ft_putwchar(wchar_t c)
{
	int size;

	size = ft_sizebyte((long)c);
	if (size < 8)
		ft_putchar(c);
	else if (size < 12)
	{
		ft_write(c, 192, 0, 6);
		ft_write(c, 128, 26, 26);
	}
	else if (size < 17)
	{
		ft_write(c, 224, 0, 12);
		ft_write(c, 128, 20, 26);
		ft_write(c, 128, 26, 26);
	}
	else if (size < 22)
	{
		ft_write(c, 240, 0, 18);
		ft_write(c, 128, 14, 26);
		ft_write(c, 128, 20, 26);
		ft_write(c, 128, 26, 26);
	}
}
