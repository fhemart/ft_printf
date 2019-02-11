/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 22:43:30 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 22:34:48 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_intlen(long long int n)
{
	size_t			len;
	size_t			neg;

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

static void			fn2(char **str, long long *n2)
{
	if (*n2 == -9223372036854775807 - 1)
	{
		(*str)[1] = '9';
		*n2 = 223372036854775808;
	}
	else
		*n2 = *n2 * -1;
}

char				*ft_llitoa(long long int n)
{
	char			*str;
	size_t			i;
	long long		n2;

	n2 = (long long)n;
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
