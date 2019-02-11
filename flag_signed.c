/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:36:46 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:46:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*flag_d(va_list arg, char *ptr, t_str *retstr)
{
	int				d;
	char			*tmp;

	d = 0;
	retstr->ptrlast = ptr + 2;
	if (conv_signed(&tmp, arg, retstr) == 0)
	{
		d = va_arg(arg, int);
		tmp = ft_itoa(d);
	}
	if (d < 0)
		retstr->neg = 1;
	if (d < 0 && retstr->space == 1 && retstr->left == 1)
		retstr->space = 0;
	if (retstr->plus == 1 && d >= 0)
		ft_strrjoin(retstr, "+", tmp, &tmp);
	if ((retstr->setpre == 1 && d == 0) || (int)ft_strlen(tmp) < retstr->pre ||
			((retstr->plus == 1 || retstr->neg == 1)
				&& (int)ft_strlen(tmp + 1) < retstr->pre))
		formatpre(&tmp, retstr);
	formatstr(&tmp, retstr);
	return (tmp);
}

char				*flag_dd(va_list arg, char *ptr, t_str *retstr)
{
	long int		d;
	char			*tmp;

	d = 0;
	retstr->ptrlast = ptr + 2;
	if (conv_signed(&tmp, arg, retstr) == 0)
	{
		d = va_arg(arg, long int);
		tmp = ft_llitoa(d);
	}
	if (d < 0)
		retstr->neg = 1;
	if (d < 0 && retstr->space == 1 && retstr->left == 1)
		retstr->space = 0;
	if (retstr->plus == 1 && d >= 0)
		ft_strrjoin(retstr, "+", tmp, &tmp);
	if ((retstr->setpre == 1 && d == 0) || (int)ft_strlen(tmp) < retstr->pre
			|| ((retstr->plus == 1 || retstr->neg == 1)
				&& (int)ft_strlen(tmp + 1) < retstr->pre))
		formatpre(&tmp, retstr);
	formatstr(&tmp, retstr);
	return (tmp);
}
