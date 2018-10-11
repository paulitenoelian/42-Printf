/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:11:46 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/05 07:11:47 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	val_oct(unsigned long long *nbr)
{
	int octal;

	octal = 0;
	if (*nbr & (long long)1)
		octal = 1;
	if (*nbr & (long long)2)
		octal = octal + 2;
	if (*nbr & (long long)4)
		octal = octal + 4;
	*nbr = *nbr >> 3;
	return (octal);
}

char		*ft_lltoao(unsigned long long nbr)
{
	return (ft_base(nbr, val_oct));
}
