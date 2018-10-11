/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:11:10 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/05 07:11:13 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	val_bin(unsigned long long *nbr)
{
	int bin;

	bin = 0;
	if (*nbr & (long long)1)
		bin++;
	*nbr = *nbr >> 1;
	return (bin);
}

char		*ft_lltoab(unsigned long long nbr)
{
	return (ft_base((long long)nbr, val_bin));
}
