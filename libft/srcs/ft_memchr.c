/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:28:23 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/23 12:06:03 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	i;

	p = (unsigned char *)s;
	i = (unsigned char)c;
	while (n--)
	{
		if (*p == i)
			return (p);
		p++;
	}
	return (NULL);
}
