/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:29:30 by npaulite          #+#    #+#             */
/*   Updated: 2018/07/22 17:24:42 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;

	tmp = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, s1);
	return (tmp);
}
