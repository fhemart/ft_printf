/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:41:17 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:46:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						checkflag(char *ptr)
{
	char				*control;
	int					pos;

	pos = -1;
	control = "sSpdDioOuUxXcC%";
	while (*control)
	{
		pos++;
		if (*control == *(ptr + 1))
			return (pos);
		control++;
	}
	return (16);
}

char					*flag_per(va_list arg, char *ptr, t_str *retstr)
{
	char				*str;
	va_list				trash;

	va_copy(trash, arg);
	str = ft_strnew2(retstr, 2);
	str[0] = '%';
	retstr->ptrlast = ptr + 2;
	retstr->space = 0;
	formatstr(&str, retstr);
	va_end(trash);
	return (str);
}

static void				flag_p_spec(t_str *retstr, char **str)
{
	if (retstr->z == 0)
	{
		*str = ft_strnew2(retstr, 3);
		*str = ft_strcpy(*str, "0x0");
		formatstr(str, retstr);
	}
	else
	{
		*str = ft_strnew2(retstr, 0);
		retstr->min_size = retstr->min_size - 3;
		formatstr(str, retstr);
		ft_strrjoin(retstr, "0x0", *str, str);
	}
}

char					*flag_p(va_list arg, char *ptr, t_str *retstr)
{
	unsigned long int	p;
	char				*str;

	retstr->ptrlast = ptr + 2;
	retstr->space = 0;
	retstr->plus = 0;
	retstr->neg = 0;
	p = va_arg(arg, unsigned long int);
	if (p == 0 && retstr->setpre == 0)
	{
		flag_p_spec(retstr, &str);
		return (str);
	}
	retstr->z = 0;
	str = lconvertbase10(retstr, p, 16);
	if (str[0] == '0')
		str[0] = '\0';
	if (retstr->setpre == 1)
		formatpre(&str, retstr);
	ft_strrjoin(retstr, "0x", str, &str);
	formatstr(&str, retstr);
	return (str);
}
