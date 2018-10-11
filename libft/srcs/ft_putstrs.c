/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:23:40 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:27:08 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstrs(char const *s)
{
	size_t	i;
	ssize_t	w_symb;

	i = 0;
	w_symb = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		w_symb += write(1, &s[i], 1);
		i++;
	}
	return (w_symb);
}
