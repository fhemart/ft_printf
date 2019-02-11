/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:20:33 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/14 12:30:13 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_signed2(char **str, va_list arg, t_str *retstr)
{
	if (retstr->h == 1)
	{
		*str = ft_stoa(va_arg(arg, int));
		return (1);
	}
	else if (retstr->l == 1)
	{
		*str = ft_llitoa(va_arg(arg, long int));
		return (1);
	}
	else if (retstr->j == 1)
	{
		*str = ft_imtoa(va_arg(arg, intmax_t));
		return (1);
	}
	else if (retstr->zz == 1)
	{
		*str = ft_llitoa(va_arg(arg, size_t));
		return (1);
	}
	return (0);
}

int			conv_signed(char **str, va_list arg, t_str *retstr)
{
	if (retstr->hh == 1)
	{
		*str = ft_ctoa(va_arg(arg, int));
		return (1);
	}
	else if (retstr->ll == 1)
	{
		*str = ft_llitoa(va_arg(arg, long long int));
		return (1);
	}
	return (conv_signed2(str, arg, retstr));
}
