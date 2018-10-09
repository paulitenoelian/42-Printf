/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 07:01:57 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/06 10:59:13 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			ft_flags(t_format *format, char *str, int *i)
{
	while (str[*i] != '\0' && is_flags(str[*i]) == 1)
	{
		if (str[*i] == '+')
			format->sign = '+';
		else if (str[*i] == ' ' && format->sign != '+')
			format->sign = ' ';
		else if (str[*i] == '-')
			format->flags = '-';
		else if (str[*i] == '0' && format->flags != '-')
			format->flags = '0';
		else if (str[*i] == '#')
			format->pre = '#';
		(*i)++;
	}
}

static void			ft_modifier(t_format *format, char *str, int *i)
{
	while (str[*i] != '\0' && is_modifier(&str[*i]) > 0)
	{
		if (is_modifier(&str[*i]) == 1 && is_modifier(format->modifier) <= 1)
		{
			format->modifier = "hh";
			(*i)++;
		}
		else if (str[*i] == 'h' && is_modifier(format->modifier) <= 2)
			format->modifier = "h";
		else if (str[*i] == 'l' && str[*i + 1] == 'l')
		{
			format->modifier = "ll";
			(*i)++;
		}
		else if (str[*i] == 'l' && is_modifier(format->modifier) != 5)
			format->modifier = "l";
		else if (str[*i] == 'j' && is_modifier(format->modifier) <= 3)
			format->modifier = "j";
		else if (str[*i] == 'z')
			format->modifier = "z";
		(*i)++;
	}
}

static t_format		*re_format(void)
{
	t_format *format;

	format = (t_format *)malloc(sizeof(t_format));
	format->flags = '\0';
	format->sign = '\0';
	format->pre = '\0';
	format->width = NULL;
	format->precision = NULL;
	format->modifier = NULL;
	format->type = '\0';
	return (format);
}

static void			free_format(t_format *format)
{
	if (format->precision != NULL)
	{
		if (format->precision[0] >= '0' && format->precision[0] <= '9')
			free(format->precision);
	}
	if (format->width != NULL)
	{
		if (format->width[0] >= '0' && format->width[0] <= '9')
			free(format->width);
	}
	free(format);
}

int					ft_format(va_list lst, const char *s, int *i)
{
	t_format	*format;
	int			x;
	char		*str;

	str = (char *)s;
	x = 0;
	format = re_format();
	while (str[*i] != '\0')
	{
		ft_flags(format, str, i);
		ft_wp(format, lst, str, i);
		ft_wp(format, lst, str, i);
		ft_modifier(format, str, i);
		if ((x = ft_type(format, lst, str[*i])) != 0)
		{
			(*i)++;
			break ;
		}
	}
	free_format(format);
	return (x);
}
