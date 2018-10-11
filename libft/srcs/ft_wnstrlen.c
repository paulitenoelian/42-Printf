/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wnstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:25:48 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/04 09:25:50 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wnstrlen(wchar_t *str, int lgt)
{
	int len;
	int i;
	int tmp;

	i = 0;
	len = 0;
	tmp = 0;
	while (str[i] != '\0')
	{
		tmp = len;
		len = tmp + ft_sizewchar((long)str[i]);
		if (len > lgt)
			break ;
		i++;
	}
	return (tmp);
}
