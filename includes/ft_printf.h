/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:45:45 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/06 12:21:45 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>

typedef struct	s_format
{
	char		flags;
	char		pre;
	char		sign;
	char		*width;
	char		*precision;
	char		*modifier;
	char		type;
}				t_format;

int				ft_printf(const char *str, ...);
int				change_color(char *str, int i);
int				ft_type(t_format *format, va_list lst, char str);
int				ft_sc(t_format format, va_list lst, char str);
int				ft_format(va_list lst, const char *s, int *i);
void			ft_wp(t_format *format, va_list lst, char *str, int *i);
int				write_nbr(t_format format, long long nbr);
char			*add_width(t_format format, wchar_t *type, int *width);
char			*fill_zero(t_format format, char *type, int width);
int				no_print(t_format format, char *word);
int				is_dioux(char type);
int				is_flags(char str);
int				is_str(char type);
int				is_unsigned(char type);
int				is_modifier(char *str);

#endif
