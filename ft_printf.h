/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:33 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/22 00:38:56 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct	s_str
{
	char		*returnstr;
	char		*ptrlast;
	char		*bad;
	int			min_size;
	int			z;
	int			space;
	int			left;
	int			plus;
	int			neg;
	int			pre;
	int			setpre;
	int			diese;
	int			ll;
	int			hh;
	int			l;
	int			h;
	int			j;
	int			zz;
	int			conv;
	int			len;
	int			spec;
	int			spec2;
}				t_str;
char			*get_res(int index, va_list arg, char *ptr, t_str *retstr);
char			*ft_strnew2(t_str *retstr, size_t size);
char			*ft_strdup2(t_str *retstr, const char *src);
int				init(t_str **retstr, char *str);
int				finalret(t_str **retstr);
void			skip_garbage(char **ptr, t_str *retstr);
void			formatpre(char **str, t_str *retstr);
char			*flag_dd(va_list arg, char *ptr, t_str *retstr);
char			*flag_c(va_list arg, char *ptr, t_str *retstr);
char			*flag_per(va_list arg, char *ptr, t_str *retstr);
int				checkflag(char *ptr);
int				checkcastdouble(char **ptr, t_str *retstr);
void			freejoin(char **src, char **dest, t_str *retstr);
int				checkpre(char **ptr, t_str *retstr, va_list arg);
int				checkmod(char **ptr, t_str *retstr, va_list arg);
char			*flag_nop(va_list arg, char *ptr, t_str *retstr);
char			*flag_u(va_list arg, char *ptr, t_str *retstr);
char			*flag_uu(va_list arg, char *ptr, t_str *retstr);
char			*flag_p(va_list arg, char *ptr, t_str *retstr);
char			*flag_oo(va_list arg, char *ptr, t_str *retstr);
char			*flag_o(va_list arg, char *ptr, t_str *retstr);
char			*flag_xx(va_list arg, char *ptr, t_str *retstr);
char			*flag_x(va_list arg, char *ptr, t_str *retstr);
char			*flag_d(va_list arg, char *ptr, t_str *retstr);
char			*flag_s(va_list arg, char *ptr, t_str *retstr);
char			*flag_cc(va_list arg, char *ptr, t_str *retstr);
char			*flag_ss(va_list arg, char *ptr, t_str *retstr);
int				firstoct(wchar_t wchar, size_t len);
char			*lastoct(t_str *retstr, wchar_t wchar);
size_t			strwcharlen(t_str *retstr, wchar_t *strw);
int				bit6(wchar_t wchar);
size_t			wcharlen(t_str *retstr, wchar_t wchar);
int				conv_signed(char **str, va_list arg, t_str *ret_str);
void			freejoin(char **src, char **dest, t_str *retstr);
int				conv_signedb(char **str, va_list arg, t_str *ret_str, int base);
int				conv_unsigned(char **str, va_list arg, t_str *retstr);
int				ft_printf(const char *format, ...);
void			formatstr(char **str, t_str *retstr);
char			*convertbase10(t_str *retstr, unsigned int nb, int base);
char			*sconvertbase10(t_str *retstr, unsigned short nb, int base);
char			*cconvertbase10(t_str *retstr, int nb, int base);
char			*lconvertbase10(t_str *retstr, unsigned long nb, int base);
char			*llconvertbase10(t_str *retstr, uintmax_t nb, int base);
char			*imconvertbase10(t_str *retstr, uintmax_t nb, int base);
char			*stconvertbase10(t_str *retstr, size_t nb, int base);
char			*get_res(int index, va_list arg, char *ptr, t_str *retstr);
void			ft_strrjoin(t_str *retstr, char *s1, char *s2, char **dest);
#endif
