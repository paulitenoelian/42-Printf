/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:30:49 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/22 17:50:07 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	d;
	size_t	s;
	size_t	x;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	x = d;
	if (size < d + 1)
		return (s + size);
	if (size > d + 1)
	{
		while (x < size - 1)
			*(dst + x++) = *(src + i++);
		*(dst + x) = '\0';
	}
	return (d + s);
}
