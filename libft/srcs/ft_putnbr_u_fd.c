/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:52:12 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/12 16:52:14 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u_fd(intmax_t nbr, int fd)
{
	write(1, "-", _NEGATIVE(nbr));
	ft_putnbr_u_base_fd(_ABS(nbr), _DEC, fd);
}
