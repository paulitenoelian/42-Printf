/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:14:21 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/06 09:14:23 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		no_print(t_format format, char *word)
{
	if (format.precision == NULL)
		return (0);
	if (format.precision[0] == '0' || format.precision[0] == '.')
	{
		if (format.pre == '#' && (format.type == 'o' || format.type == 'O'))
			return (0);
		if (ft_strcmp(word, "0") == 0)
			return (1);
	}
	return (0);
}
