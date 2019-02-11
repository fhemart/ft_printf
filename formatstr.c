/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:13:50 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:46:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkz(t_str *retstr)
{
	if ((retstr->space == 1 && retstr->z == 1)
			|| (retstr->neg == 1 && retstr->z == 1)
			|| (retstr->plus == 1 && retstr->z == 1))
		return (1);
	return (0);
}

static void	fillstr(char **tmp, t_str *retstr, size_t len)
{
	if (retstr->z == 1)
		ft_memset((void*)*tmp + 1, '0', retstr->min_size - len);
	else
		ft_memset((void*)*tmp + 1, ' ', retstr->min_size - len);
}

void		formatstr(char **str, t_str *retstr)
{
	char	*tmp;

	if (retstr->space == 1 && retstr->neg == 0 && retstr->plus == 0)
		ft_strrjoin(retstr, " ", *str, str);
	if (retstr->min_size > (int)ft_strlen(*str))
	{
		tmp = ft_strnew2(retstr, retstr->min_size);
		tmp[0] = (*str)[0];
		if (retstr->left == 1)
		{
			ft_memset((void*)tmp + 1, ' ', retstr->min_size - ft_strlen(*str));
			ft_strrjoin(retstr, *str, tmp + 1, str);
			if (retstr->spec == 1)
				retstr->len = retstr->len + (retstr->min_size - 2);
		}
		else
		{
			fillstr(&tmp, retstr, ft_strlen(*str));
			if (checkz(retstr))
				ft_strrjoin(retstr, tmp, *str + 1, str);
			else
				ft_strrjoin(retstr, tmp + 1, *str, str);
		}
		free(tmp);
	}
}
