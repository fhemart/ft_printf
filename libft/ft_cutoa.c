/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:36:54 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 22:20:01 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(unsigned int n)
{
	size_t		len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	(len > 0) ? len : len++;
	return (len);
}

char			*ft_cutoa(unsigned int n)
{
	char		*str;
	size_t		i;
	long		n2;

	if (n > 255 && n < 32768)
		n = (unsigned char)n;
	n2 = n;
	i = ft_intlen(n);
	if (!(str = malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
	str[i] = '\0';
	i--;
	while (n2 > 9)
	{
		str[i] = (n2 % 10) + 48;
		n2 = n2 / 10;
		i--;
	}
	str[i] = n2 + 48;
	return (str);
}
