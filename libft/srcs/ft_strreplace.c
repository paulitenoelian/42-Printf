/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:24:04 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/23 14:31:32 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *from, char *to)
{
	char		*c;
	char		*new;
	size_t		i;
	size_t		j;

	new = NULL;
	if ((c = ft_strstr(str, from)))
	{
		i = c - str;
		j = ft_strlen(c + ft_strlen(from));
		new = ft_memalloc(sizeof(char) * (i + ft_strlen(to) + j + 1));
		if (new)
		{
			new = ft_strncpy(new, str, i);
			new = ft_strcat(new, to);
			new = ft_strcat(new, c + ft_strlen(from));
		}
	}
	return (new);
}
