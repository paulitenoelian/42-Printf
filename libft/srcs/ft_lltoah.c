/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoah.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:11:27 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/05 07:11:28 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	val_hex(uint64_t *nbr)
{
	int hexa;

	hexa = 0;
	if (*nbr & (long long)1)
		hexa = 1;
	if (*nbr & (long long)2)
		hexa = hexa + 2;
	if (*nbr & (long long)4)
		hexa = hexa + 4;
	if (*nbr & (long long)8)
		hexa = hexa + 8;
	*nbr = *nbr >> 4;
	if (hexa > 9)
		hexa = hexa + 39;
	return (hexa);
}

static int	val_hex2(uint64_t *nbr)
{
	int hexa;

	hexa = 0;
	if (*nbr & (long long)1)
		hexa = 1;
	if (*nbr & (long long)2)
		hexa = hexa + 2;
	if (*nbr & (long long)4)
		hexa = hexa + 4;
	if (*nbr & (long long)8)
		hexa = hexa + 8;
	*nbr = *nbr >> 4;
	if (hexa > 9)
		hexa = hexa + 7;
	return (hexa);
}

char		*ft_lltoah(unsigned long long nbr, int size)
{
	if (size == 1)
		return (ft_base((uint64_t)nbr, val_hex));
	else if (size == 2)
		return (ft_base((uint64_t)nbr, val_hex2));
	return (NULL);
}
