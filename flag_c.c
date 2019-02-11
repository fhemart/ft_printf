/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:12:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:46:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		checkpreforc(char **str, t_str *retstr)
{
	char			*tmp;

	tmp = NULL;
	if (retstr->spec == 1)
	{
		tmp = ft_strchr(*str, '*');
		retstr->len = retstr->len + 1;
		*tmp = '\0';
	}
}

char			*flag_c(va_list arg, char *ptr, t_str *retstr)
{
	unsigned int	i;
	char			*str;

	retstr->space = 0;
	i = 0;
	if (retstr->l == 1)
		return (flag_cc(arg, ptr, retstr));
	i = va_arg(arg, int);
	if (i == 0)
	{
		if (retstr->left == 1)
			retstr->len = retstr->len + 1;
		retstr->spec = 1;
		i = '*';
	}
	str = ft_strnew2(retstr, 2);
	str[0] = i;
	retstr->ptrlast = ptr + 2;
	formatstr(&str, retstr);
	checkpreforc(&str, retstr);
	return (str);
}

char			*flag_cc(va_list arg, char *ptr, t_str *retstr)
{
	wchar_t			wchar;
	char			*str;
	va_list			cpy;

	retstr->space = 0;
	va_copy(cpy, arg);
	wchar = va_arg(arg, wchar_t);
	if (wcharlen(retstr, wchar) == 1)
	{
		str = flag_c(cpy, ptr, retstr);
		va_end(cpy);
		return (str);
	}
	str = lastoct(retstr, wchar);
	va_end(cpy);
	retstr->ptrlast = ptr + 2;
	formatstr(&str, retstr);
	return (str);
}
