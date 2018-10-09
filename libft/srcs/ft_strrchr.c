/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:31:25 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/22 11:33:50 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*x;

	x = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			x = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (x);
}
