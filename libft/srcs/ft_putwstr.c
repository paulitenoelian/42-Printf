/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:26:53 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/05 07:26:54 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putwchar(str[i]);
		i++;
	}
}
