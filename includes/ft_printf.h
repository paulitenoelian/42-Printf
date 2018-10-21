/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:01:47 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/21 07:53:55 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define _MIN(a, b) a < b ? a : b
# define _MAX(a, b) a > b ? a : b
# define _SCR1 p->size == 'H' || p->size == 'h'
# define _SCR2 p->size == 'H' || p->size == 'h' || p->size == 'l'
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <limits.h>

typedef struct		s_p
{
	int				hash : 1;
	int				zero : 1;
	int				minus : 1;
	int				plus : 1;
	int				space : 1;
	int				is_width : 1;
	int				is_precision : 1;
	int				width;
	int				precision;
	char			size;
}					t_p;

int					ft_printf(const char *format, ...);

char				*ft_check_flags(char **str, t_p *p);
char				*ft_check_width(char **str, t_p *p, va_list *ap);
char				*ft_check_precision(char **str, t_p *p, va_list *ap,\
										int pr);
char				*ft_check_size(char **str, t_p *p, char c);

int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_space(int len, int width, char c);
uintmax_t			ft_len(uintmax_t j, char *base);
uintmax_t			ft_len_j(uintmax_t j, char *base, char *front, t_p *p);
void				get_u(va_list *ap, t_p *p, uintmax_t *nbr);

intmax_t			ft_null(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_percent(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_int(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_long(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_char(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_wchar(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_str(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_wstr(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_hex(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_octal(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_unsigned(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_void(char **str, va_list *ap, t_p *p);

typedef intmax_t	(*t_print)(char**, va_list*, t_p*);
t_print				ft_get_param(char c);

intmax_t			ft_putnbr_front(uintmax_t j, char *base, t_p *p,\
									char front);
intmax_t			ft_putnbr_unsign(uintmax_t j, char *base, t_p *p,\
										char *front);

#endif
