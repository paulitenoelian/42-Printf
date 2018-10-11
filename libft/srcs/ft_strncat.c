/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:30:37 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/22 11:32:14 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = -1;
	while (*(s2 + ++j) && j < (int)n)
		*(s1 + i++) = *(s2 + j);
	*(s1 + i) = '\0';
	return (s1);
}
