/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:24:14 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:26:57 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_print_res(char *nbr_arr, long int long_n, int m_flag)
{
	size_t	len;

	len = 0;
	nbr_arr[0] = '\0';
	while (long_n > 0)
	{
		len++;
		nbr_arr[len] = long_n % 10 + '0';
		long_n = long_n / 10;
	}
	if (m_flag == 1)
		nbr_arr[++len] = '-';
	while (nbr_arr[len] != '\0')
	{
		write(1, &nbr_arr[len], 1);
		len--;
	}
}

void			ft_putnbrs(int n)
{
	char		nbr_arr[12];
	long int	long_n;
	int			m_flag;

	m_flag = 0;
	long_n = n;
	if (long_n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (long_n < 0)
	{
		m_flag = 1;
		long_n *= -1;
	}
	ft_print_res(nbr_arr, long_n, m_flag);
}
