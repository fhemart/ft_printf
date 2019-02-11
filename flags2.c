/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:30:39 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 19:16:44 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*flag_nop(va_list arg, char *ptr, t_str *retstr)
{
	char		*str;

	str = NULL;
	retstr->space = 0;
	if (ft_strchr(" +#-*", *(ptr + 1)) && *(ptr + 1) != '\0')
	{
		checkmod(&ptr, retstr, arg);
		if (ft_strchr("sSpdDioOuUxXcC%", *(ptr + 1)))
			str = get_res(checkflag(ptr), arg, ptr, retstr);
		retstr->min_size = retstr->min_size - 1;
	}
	if (!str && *(ptr + 1) == '\0')
	{
		retstr->ptrlast = ptr + 1;
		str = ft_strnew2(retstr, 0);
		retstr->min_size = retstr->min_size - 1;
	}
	else
	{
		str = ft_strnew2(retstr, 1);
		str[0] = *(ptr + 1);
		retstr->ptrlast = ptr + 2;
	}
	formatstr(&str, retstr);
	return (str);
}
