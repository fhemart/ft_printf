/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 21:18:02 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 18:45:59 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_unsignedb(char **str, va_list arg, t_str *retstr)
{
	if (retstr->h == 1)
	{
		*str = ft_lutoa(va_arg(arg, long int));
		return (1);
	}
	else if (retstr->l == 1)
	{
		*str = ft_lutoa(va_arg(arg, long int));
		return (1);
	}
	else if (retstr->j == 1)
	{
		*str = ft_imutoa(va_arg(arg, uintmax_t));
		return (1);
	}
	else if (retstr->zz == 1)
	{
		*str = ft_imutoa(va_arg(arg, uintmax_t));
		return (1);
	}
	return (0);
}

int			conv_unsigned(char **str, va_list arg, t_str *retstr)
{
	if (retstr->hh == 1)
	{
		*str = ft_cutoa(va_arg(arg, unsigned int));
		return (1);
	}
	else if (retstr->ll == 1)
	{
		*str = ft_llutoa(va_arg(arg, unsigned long long int));
		return (1);
	}
	return (conv_unsignedb(str, arg, retstr));
}

static int	conv_signedbb(char **str, va_list arg, t_str *retstr, int base)
{
	if (retstr->h == 1)
	{
		*str = sconvertbase10(retstr, va_arg(arg, unsigned int), base);
		return (1);
	}
	else if (retstr->l == 1)
	{
		*str = lconvertbase10(retstr, va_arg(arg, unsigned long int), base);
		return (1);
	}
	else if (retstr->j == 1)
	{
		*str = imconvertbase10(retstr, va_arg(arg, uintmax_t), base);
		return (1);
	}
	else if (retstr->zz == 1)
	{
		*str = stconvertbase10(retstr, va_arg(arg, size_t), base);
		return (1);
	}
	return (0);
}

int			conv_signedb(char **str, va_list arg, t_str *retstr, int base)
{
	if (retstr->hh == 1)
	{
		*str = cconvertbase10(retstr, va_arg(arg, unsigned int), base);
		return (1);
	}
	else if (retstr->ll == 1)
	{
		*str = llconvertbase10(retstr, va_arg(arg, uintmax_t), base);
		return (1);
	}
	return (conv_signedbb(str, arg, retstr, base));
}
