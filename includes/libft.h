/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:35:35 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/08 16:35:37 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define EOC	 "\033[0m"
# define RED     "\033[1;31m"
# define YELLOW  "\033[1;33m"
# define WHITE   "\033[1;37m"
# define BLACK	 "\033[0;30m"
# define GREEN	 "\033[0;32m"
# define BLUE	 "\033[0;34m"
# define PURPUL	 "\033[0;35m"
# define CYAN	 "\033[0;36m"

# define IS_NAN(num) ((num != num) ? 1 : 0)
# define IS_INF(num) ((num == (1.0 / 0.0) || num == (-1.0 / 0.0)) ? 1 : 0)


typedef struct		s_specifier
{
	int				precision;
	int				flag_minus;
	int				flag_plus;
	int				flag_spase;
	int				flag_hash;
	int				flag_zero;
	int				length;
	int				width;
	char			type;
}					t_specifier;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int g_r;
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *str, const char *sub);
char				*ft_strnstr(const char *str, const char *sub, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
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
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstfree(t_list **alst);
void				ft_lstfreeone(t_list **alst);
int					ft_lstaddend(t_list **alst, t_list *new);

int					ft_printf(char *src, ...);
char				*ft_ftoa(long double nbr, int afterpoint);
char				*ft_itoa_ll(long long int nb);
char				*ft_itoa_ull(unsigned long long nb);
char				*ft_itoa_base(int dec, int base, int up);
char				*ft_itoa_base_ull(unsigned long long dec, int base, char x);
int					ft_cat_pro(char **dest, char *src);
int					ft_nbrlen(long long int nb);
int					ft_nbrlen_u(unsigned long long nb);
unsigned long long	ft_pow(int nb, int pow);
char				*round_it(char *src);
void				set_plus(char **src, t_specifier spec);
void				set_pref(char **src, char type);
int					is_flag(char c);
int					is_type(char c);
int					is_right(char c);
void				prec_zero(char **src, int precision);
void				add_zero(char **src, t_specifier spec);
void				find_flags(t_specifier *spec, char *src);
int					find_width(char *src, va_list ap);
int					find_lenght(char *src);
int					find_precision(char *src, va_list ap);
void				ft_putchar_free(char c);
void				ft_putstr_free(char *c);
void				ft_put_unicode(wchar_t c);
void				ft_put_unicode_str(wchar_t *src);
int					ft_unicode_simblen(wchar_t c);
int					ft_unicode_strlen(wchar_t *src);
void				ft_unicode_strdel(wchar_t **as);
wchar_t				*ft_unicode_strdup(wchar_t *s1);
int					ft_consist(const char *str, const char *sub);
void				alignment_optput(t_specifier spec, char *src);
void				print_chars(t_specifier spec, va_list ap);
void				print_strings(t_specifier spec, va_list ap);
long double			use_lenght_for_f(t_specifier spec, va_list ap);
long long int		use_lenght_for_di(t_specifier spec, va_list ap);
long long int		use_lenght_for_uoxx(t_specifier spec, va_list ap);
void				print_specifier_di(t_specifier spec, long long int nbr);
void				print_specifier_u(t_specifier spec, unsigned long long nbr);
void				print_specifier_x(t_specifier spec, unsigned long long nbr);
void				print_specifier_b(t_specifier spec, unsigned long long nbr);
void				print_specifier_o(t_specifier spec, unsigned long long nbr);
void				print_specifier_f(t_specifier spec, long double nbr);
void				print_specifier_l_s(t_specifier spec, va_list ap);
void				print_specifier_s(t_specifier spec, va_list ap);
void				print_specifier_l_c(t_specifier spec, va_list ap);
void				print_specifier_c(t_specifier spec, va_list ap);
void				print_specifier_p(t_specifier spec, va_list ap);
void				print_specifier_l_w(t_specifier spec, va_list ap);
void				print_specifier_w(t_specifier spec, va_list ap);

#endif