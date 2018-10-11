/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:24:32 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:27:58 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_print_res(char *arr, long int n, int flag, int fd)
{
	size_t	len;

	len = 0;
	arr[0] = '\0';
	while (n > 0)
	{
		len++;
		arr[len] = n % 10 + '0';
		n = n / 10;
	}
	if (flag == 1)
		arr[++len] = '-';
	while (arr[len] != '\0')
	{
		write(fd, &arr[len], 1);
		len--;
	}
}

void			ft_putnbrs_fd(int n, int fd)
{
	char		nbr_arr[12];
	long int	long_n;
	int			m_flag;

	m_flag = 0;
	long_n = n;
	if (long_n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (long_n < 0)
	{
		m_flag = 1;
		long_n *= -1;
	}
	ft_print_res(nbr_arr, long_n, m_flag, fd);
}
