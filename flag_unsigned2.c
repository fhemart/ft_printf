/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_unsigned2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:26:46 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/17 18:32:29 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*flag_u(va_list arg, char *ptr, t_str *retstr)
{
	unsigned int		u;
	char				*str;

	retstr->ptrlast = ptr + 2;
	retstr->space = 0;
	if (conv_unsigned(&str, arg, retstr) == 0)
	{
		u = va_arg(arg, unsigned int);
		str = ft_utoa(u);
	}
	if (retstr->setpre > 0)
		formatpre(&str, retstr);
	formatstr(&str, retstr);
	return (str);
}

char					*flag_uu(va_list arg, char *ptr, t_str *retstr)
{
	unsigned long int	u;
	char				*str;

	retstr->ptrlast = ptr + 2;
	retstr->space = 0;
	if (conv_unsigned(&str, arg, retstr) == 0)
	{
		u = va_arg(arg, unsigned long int);
		str = ft_llutoa(u);
	}
	if (retstr->pre > 0)
		formatpre(&str, retstr);
	formatstr(&str, retstr);
	return (str);
}
