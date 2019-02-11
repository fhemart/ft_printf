/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 01:05:36 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 22:35:53 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_intlen(unsigned long int n)
{
	size_t			len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	(len > 0) ? len : len++;
	return (len);
}

char				*ft_lutoa(unsigned long int n)
{
	char			*str;
	size_t			i;
	unsigned long	n2;

	n2 = (int)n;
	i = ft_intlen(n);
	if (!(str = malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
	if (n2 > 4294967297 && n > 4294967297)
	{
		str = ft_llutoa(n2);
		return (str);
	}
	str[i] = '\0';
	i--;
	while (n > 9)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	str[i] = n + 48;
	return (str);
}
