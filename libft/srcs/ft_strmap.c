/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:27:05 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/23 13:26:20 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (!s)
		return (NULL);
	i = -1;
	new = ft_strnew(ft_strlen(s));
	if (!new)
		return (NULL);
	while (*(s + ++i))
		*(new + i) = f(*(s + i));
	return (new);
}
