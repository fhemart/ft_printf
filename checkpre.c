/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:58:21 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:46:14 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				checkpre(char **ptr, t_str *retstr, va_list arg)
{
	int			star;

	star = 0;
	retstr->pre = 0;
	if (*(*ptr + 1) == '.')
	{
		retstr->setpre = 1;
		*ptr = *ptr + 1;
		while (ft_isdigit(*(*ptr + 1)) || *(*ptr + 1) == '*')
		{
			if (*(*ptr + 1) >= 48 && *(*ptr + 1) <= 57)
				retstr->pre = (retstr->pre * 10) + (*(*ptr + 1) - 48);
			if (*(*ptr + 1) == '*')
			{
				star = va_arg(arg, int);
				if (!ft_isdigit(*(*ptr + 2)) && star != 0)
					retstr->setpre = 0;
				retstr->pre = star;
			}
			*ptr = *ptr + 1;
		}
	}
	return (0);
}

static void		checkprezero(char **str, t_str *retstr)
{
	if (retstr->pre == 0)
	{
		free(*str);
		*str = ft_strnew2(retstr, 0);
	}
}

static void		freedouble(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
}

void			formatpre(char **str, t_str *retstr)
{
	char		*tmp;
	char		*tmp2;

	if ((retstr->plus == 1 || retstr->neg == 1) && retstr->pre > 0
			&& retstr->pre >= (int)ft_strlen(*str))
	{
		tmp = ft_strnew2(retstr, (retstr->pre + 2) - (int)ft_strlen(*str));
		ft_memset((void*)tmp + 1, '0', retstr->pre + 1 - (int)ft_strlen(*str));
		tmp[0] = (*str)[0];
		tmp2 = ft_strdup2(retstr, *str + 1);
		free(*str);
		*str = ft_strjoin(tmp, tmp2);
		freedouble(&tmp, &tmp2);
	}
	else if (retstr->plus == 0 && retstr->neg == 0 && retstr->pre > 0
			&& retstr->pre >= (int)ft_strlen(*str))
	{
		tmp = ft_strnew2(retstr, (retstr->pre + 1) - (int)ft_strlen(*str));
		ft_memset((void*)tmp, '0', retstr->pre - (int)ft_strlen(*str));
		tmp2 = ft_strdup2(retstr, *str);
		free(*str);
		*str = ft_strjoin(tmp, tmp2);
		freedouble(&tmp, &tmp2);
	}
	checkprezero(str, retstr);
}
