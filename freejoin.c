/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freejoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:02:02 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 20:22:48 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				freejoin(char **src, char **dest, t_str *retstr)
{
	char			*tmp;

	tmp = ft_strsub(*dest, 0, retstr->len + 1);
	free(*dest);
	if (retstr->spec == 1)
	{
		retstr->spec = 0;
		*dest = ft_strnew2(retstr, retstr->len + 1);
		ft_memcpy((void*)*dest, (void*)tmp,
				retstr->len - ((int)ft_strlen(*src) + 1));
		ft_memcpy((void*)*(dest) + (int)ft_strlen(*dest),
				(void*)*src, (ft_strlen(*src) + 1 + retstr->min_size));
	}
	else
	{
		*dest = ft_strnew2(retstr, retstr->len);
		ft_memcpy((void*)*dest, (void*)tmp, retstr->len - (int)ft_strlen(*src));
		ft_memcpy((void*)*(dest) + (retstr->len - (int)ft_strlen(*src)),
				(void*)*src, ft_strlen(*src));
	}
	free(tmp);
	free(*src);
}
