/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:36:50 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/25 16:02:46 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_res(int index, va_list arg, char *ptr, t_str *retstr)
{
	static char *(*f[17])() = {flag_s, flag_ss, flag_p, flag_d, flag_dd, flag_d
		, flag_o, flag_oo, flag_u, flag_uu, flag_x, flag_xx, flag_c, flag_cc
			, flag_per, flag_nop, flag_nop};

	return (f[index](arg, ptr, retstr));
}

static void			checkall(char **ptr, t_str *retstr, va_list arg)
{
	checkmod(ptr, retstr, arg);
	checkpre(ptr, retstr, arg);
	checkcastdouble(ptr, retstr);
}

static int			beforeloop(va_list arg, char **ptr,
						char **tmp, t_str *retstr)
{
	retstr->len = ft_strlen(retstr->returnstr);
	checkall(ptr, retstr, arg);
	skip_garbage(ptr, retstr);
	*tmp = get_res(checkflag(*ptr), arg, *ptr, retstr);
	if (retstr->spec2 == -1)
		return (finalret(&retstr));
	retstr->len = retstr->len + ft_strlen(*tmp);
	freejoin(tmp, &retstr->returnstr, retstr);
	while ((*ptr = ft_strchr(retstr->ptrlast, '%')) != NULL)
	{
		*tmp = ft_strsub(retstr->ptrlast, 0, ft_strlen(retstr->ptrlast) -
				ft_strlen(*ptr));
		retstr->len = retstr->len + (ft_strlen(retstr->ptrlast) -
				ft_strlen(*ptr));
		freejoin(tmp, &retstr->returnstr, retstr);
		checkall(ptr, retstr, arg);
		*tmp = get_res(checkflag(*ptr), arg, *ptr, retstr);
		if (retstr->spec2 == -1)
			return (finalret(&retstr));
		retstr->len = retstr->len + ft_strlen(*tmp);
		freejoin(tmp, &retstr->returnstr, retstr);
	}
	return (0);
}

int					ft_printf(const char *format, ...)
{
	char			*str;
	char			*tmp;
	t_str			*retstr;
	char			*ptr;
	va_list			arg;

	va_start(arg, format);
	str = (char*)format;
	if (init(&retstr, str) == -1)
		return (-1);
	if ((ptr = ft_strchr(str, '%')) == NULL)
	{
		retstr->len = ft_strlen(str);
		retstr->returnstr = ft_strdup2(retstr, str);
		return (finalret(&retstr));
	}
	retstr->returnstr = ft_strsub(str, ft_strlen(str) -
			ft_strlen(retstr->ptrlast), ft_strlen(str) - ft_strlen(ptr));
	if ((beforeloop(arg, &ptr, &tmp, retstr)) == -1)
		return (-1);
	tmp = ft_strdup2(retstr, retstr->ptrlast);
	retstr->len = retstr->len + ft_strlen(retstr->ptrlast);
	freejoin(&tmp, &retstr->returnstr, retstr);
	va_end(arg);
	return (finalret(&retstr));
}
