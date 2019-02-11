/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:14:04 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 22:34:50 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(intmax_t n)
{
	size_t		len;
	size_t		neg;

	len = 0;
	neg = 0;
	(n < 0) ? neg = 1 : neg;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	(len > 0) ? len : len++;
	return (len + neg);
}

static void		fn2(char **str, intmax_t *n2)
{
	if (*n2 == -9223372036854775807 - 1)
	{
		(*str)[1] = '9';
		*n2 = 223372036854775808;
	}
	else
		*n2 = *n2 * -1;
}

char			*ft_imtoa(intmax_t n)
{
	char		*str;
	size_t		i;
	intmax_t	n2;

	n2 = (intmax_t)n;
	i = ft_intlen(n);
	if (!(str = malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
	if (n2 < 0)
	{
		str[0] = '-';
		fn2(&str, &n2);
	}
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
