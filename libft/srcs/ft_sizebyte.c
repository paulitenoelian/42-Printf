/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizebyte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:29:13 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/04 09:29:14 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizebyte(uint64_t nbr)
{
	int size;

	size = 0;
	while (nbr != 0)
	{
		nbr = nbr >> 1;
		size++;
	}
	return (size);
}