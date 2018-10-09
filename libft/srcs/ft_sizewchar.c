/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizewchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:27:41 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/04 09:28:35 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizewchar(long n)
{
	int size;

	size = ft_sizebyte(n);
	if (size < 8)
		return (1);
	else if (size < 12)
		return (2);
	else if (size < 17)
		return (3);
	else if (size < 22)
		return (4);
	return (0);
}
