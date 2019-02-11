/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sttoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:26:05 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 22:37:22 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(size_t n)
{
	size_t		len;
	size_t		neg;

	len = 0;
	neg = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len + neg);
}

void			ft_sttoa(size_t n, char **str)
{
	size_t		i;
	size_t		n2;

	i = ft_intlen(n);
	if (i == 0)
		i++;
	i--;
	while (n2 > 9)
	{
		(*str)[i] = (n2 % 10) + 48;
		n2 = n2 / 10;
		i--;
	}
	(*str)[i] = n2 + 48;
}
