/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:50:10 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/14 18:20:21 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			checkcast(char **ptr, t_str *retstr)
{
	if (*(*ptr + 1) == 'l')
	{
		retstr->l = 1;
		*ptr = *ptr + 1;
		return (1);
	}
	if (*(*ptr + 1) == 'h')
	{
		retstr->h = 1;
		*ptr = *ptr + 1;
		return (1);
	}
	if (*(*ptr + 1) == 'j')
	{
		retstr->j = 1;
		*ptr = *ptr + 1;
		return (1);
	}
	if (*(*ptr + 1) == 'z')
	{
		retstr->zz = 1;
		*ptr = *ptr + 1;
		return (1);
	}
	return (0);
}

int					checkcastdouble(char **ptr, t_str *retstr)
{
	if (*(*ptr + 1) == 'l' && *(*ptr + 2) == 'l'
			&& !ft_strchr("lhjz", *(*ptr + 3)))
	{
		retstr->ll = 1;
		*ptr = *ptr + 2;
		return (1);
	}
	if (*(*ptr + 1) == 'h' && *(*ptr + 2) == 'h'
			&& !ft_strchr("lhjz", *(*ptr + 3)))
	{
		retstr->hh = 1;
		*ptr = *ptr + 2;
		return (1);
	}
	return (checkcast(ptr, retstr));
}
