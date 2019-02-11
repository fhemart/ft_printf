/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:20:25 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:50:31 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strnew2(t_str *retstr, size_t size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * size + 1)))
	{
		retstr->spec2 = -1;
		return (retstr->bad);
	}
	ft_memset(str, 0, (sizeof(char) * size + 1));
	retstr->spec2 = 0;
	return (str);
}
