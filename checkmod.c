/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:18:35 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 00:51:49 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		resetmod(t_str *retstr)
{
	retstr->min_size = 0;
	retstr->z = 0;
	retstr->space = 0;
	retstr->left = 0;
	retstr->plus = 0;
	retstr->neg = 0;
	retstr->diese = 0;
	retstr->setpre = 0;
}

static void		checkmodstar(char **ptr, t_str *retstr, int len)
{
	if (!ft_isdigit(*(*ptr + 2)))
	{
		retstr->min_size = len;
		if (retstr->min_size < 0)
		{
			retstr->left = 1;
			retstr->min_size = retstr->min_size * -1;
		}
	}
}

int				checkmod(char **ptr, t_str *retstr, va_list arg)
{
	resetmod(retstr);
	while (ft_isdigit(*(*ptr + 1)) || *(*ptr + 1) == '*' || *(*ptr + 1) == ' '
			|| *(*ptr + 1) == '-' || *(*ptr + 1) == '+' || *(*ptr + 1) == '#')
	{
		if (*(*ptr + 1) == ' ' && retstr->space == 0 && retstr->plus == 0)
			retstr->space = 1;
		if (*(*ptr + 1) == '+')
		{
			retstr->plus = 1;
			retstr->space = 0;
		}
		if (*(*ptr + 1) == '#')
			retstr->diese = 1;
		if (*(*ptr + 1) == 48 && retstr->min_size == 0)
			retstr->z = 1;
		if (*(*ptr + 1) == '-')
			retstr->left = 1;
		if (*(*ptr + 1) >= 48 && *(*ptr + 1) <= 57)
			retstr->min_size = (retstr->min_size * 10) + (*(*ptr + 1) - 48);
		if (*(*ptr + 1) == '*')
			checkmodstar(ptr, retstr, va_arg(arg, int));
		*ptr = *ptr + 1;
	}
	return (0);
}
