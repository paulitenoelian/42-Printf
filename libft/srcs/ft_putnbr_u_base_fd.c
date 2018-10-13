/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:52:44 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/12 16:52:45 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u_base_fd(uintmax_t nbr, char *base, int fd)
{
	uintmax_t len;

	len = ft_strlen(base);
	if (nbr / len)
		ft_putnbr_u_base_fd(nbr / len, base, fd);
	write(fd, (base + nbr % len), 1);
}
