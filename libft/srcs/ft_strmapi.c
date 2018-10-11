/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:27:15 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/23 13:25:41 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		*(new + i) = f(i, *(s + i));
	return (new);
}
