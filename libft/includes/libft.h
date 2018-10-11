/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaulite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:51:09 by npaulite          #+#    #+#             */
/*   Updated: 2018/10/11 12:31:10 by npaulite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# define BUFF_SIZE 4096

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char				*ft_capitalize(char *s);
void				ft_replace(char *str, char tr, char rp);
char				*ft_strreplace(char *str, char *from, char *to);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
t_list				*ft_lstrev(t_list *alst);
void				ft_lstaddback(t_list **alst, t_list *new);
int					ft_absnum(int i);
int					ft_sizebyte(uint64_t nbr);
int					ft_sizewchar(long n);
int					ft_wstrlen(wchar_t *str);
int					ft_wnstrlen(wchar_t *str, int lgt);
int					get_next_line(int const fd, char **line);
void				ft_swap(int *a, int *b);
int					ft_recursive_power(int nb, int power);
int					ft_recursive_factorial(int nb);
char				*ft_base(uint64_t nbr, int (*val)(uint64_t *nbr));
void				ft_init_str(char *str, unsigned int c, int n);
long				ft_power(int nb, int power);
char				*ft_itoah(unsigned int nbr, int size);
char				*ft_itoao(unsigned int nbr);
char				*ft_lltoa(long long nbr);
char				*ft_lltoah(unsigned long long nbr, int size);
char				*ft_lltoao(unsigned long long nbr);
char				*ft_lltoab(unsigned long long nbr);
char				*ft_ulltoa(unsigned long long nbr);
void				ft_put_error(char *str);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *str);
void				ft_putnstr(char *str, int lgt);
void				ft_putnwstr(wchar_t *str, int lgt);
size_t				ft_putchars(unsigned int c);
ssize_t				ft_putstrs(const char *s);
void				ft_putendls(const char *s);
void				ft_putnbrs(int n);
void				ft_putchars_fd(unsigned int c, int fd);
void				ft_putstrs_fd(const char *s, int fd);
void				ft_putendls_fd(const char *s, int fd);
void				ft_putnbrs_fd(int n, int fd);
#endif
