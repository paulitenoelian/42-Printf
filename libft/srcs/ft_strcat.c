/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:30:21 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/22 17:43:43 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = -1;
	j = (int)ft_strlen(s1);
	while (*(s2 + ++i))
		*(s1 + j++) = *(s2 + i);
	*(s1 + j) = '\0';
	return (s1);
}