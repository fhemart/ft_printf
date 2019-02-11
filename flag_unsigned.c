/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:57:59 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:46:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*flag_x(va_list arg, char *ptr, t_str *retstr)
{
	unsigned int		x;
	char				*str;

	retstr->ptrlast = ptr + 2;
	retstr->space = 0;
	if (conv_signedb(&str, arg, retstr, 16) == 0)
	{
		x = va_arg(arg, unsigned int);
		str = convertbase10(retstr, x, 16);
	}
	if (retstr->setpre == 1 && ((int)ft_strlen(str) < retstr->pre || x == 0))
		formatpre(&str, retstr);
	if (retstr->diese == 1 && (retstr->z == 0 || retstr->left == 1))
		if ((str[ft_strlen(str) - 1] != '0' && retstr->setpre == 0) ||
				(str[0] != 0 && retstr->setpre == 1))
			ft_strrjoin(retstr, "0x", str, &str);
	formatstr(&str, retstr);
	if (retstr->diese == 1 && retstr->z == 1 && retstr->left == 0)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	return (str);
}

char					*flag_o(va_list arg, char *ptr, t_str *retstr)
{
	unsigned int		o;
	char				*str;

	retstr->space = 0;
	retstr->ptrlast = ptr + 2;
	if (conv_signedb(&str, arg, retstr, 8) == 0)
	{
		o = va_arg(arg, unsigned int);
		str = convertbase10(retstr, o, 8);
	}
	if (str[0] == '0' && retstr->setpre == 1)
		ft_strclr(str);
	if (retstr->diese == 1 && str[0] != '0')
		ft_strrjoin(retstr, "0", str, &str);
	if (retstr->pre > 0)
		formatpre(&str, retstr);
	formatstr(&str, retstr);
	return (str);
}

char					*flag_oo(va_list arg, char *ptr, t_str *retstr)
{
	unsigned long int	o;
	char				*str;

	retstr->ptrlast = ptr + 2;
	retstr->space = 0;
	if (conv_signedb(&str, arg, retstr, 8) == 0)
	{
		o = va_arg(arg, unsigned long int);
		str = llconvertbase10(retstr, o, 8);
	}
	if (str[0] == '0' && retstr->setpre == 1)
		ft_strclr(str);
	if (retstr->diese == 1)
		ft_strrjoin(retstr, "0", str, &str);
	if (retstr->pre > 0)
		formatpre(&str, retstr);
	formatstr(&str, retstr);
	return (str);
}

static void				capitalize(char **str)
{
	size_t				i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] >= 97 && (*str)[i] <= 122)
			(*str)[i] = (*str)[i] - 32;
		i++;
	}
}

char					*flag_xx(va_list arg, char *ptr, t_str *retstr)
{
	unsigned int		x;
	char				*str;
	int					i;

	i = 0;
	retstr->ptrlast = ptr + 2;
	retstr->space = 0;
	if (conv_signedb(&str, arg, retstr, 16) == 0)
	{
		x = va_arg(arg, unsigned int);
		str = convertbase10(retstr, x, 16);
	}
	capitalize(&str);
	if (retstr->setpre == 1 && ((int)ft_strlen(str) < retstr->pre || x == 0))
		formatpre(&str, retstr);
	if (retstr->diese == 1 && (retstr->z == 0 || retstr->left == 1))
		if ((str[ft_strlen(str) - 1] != '0' && retstr->setpre == 0) ||
				(str[0] != 0 && retstr->setpre == 1))
			ft_strrjoin(retstr, "0X", str, &str);
	formatstr(&str, retstr);
	if (retstr->diese == 1 && retstr->z == 1 && retstr->left == 0)
		ft_strcpy(str, "0X");
	return (str);
}
