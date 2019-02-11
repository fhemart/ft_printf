/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:25:40 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 22:32:07 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(unsigned long long int n)
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

char			*ft_llutoa(unsigned long long int n)
{
	char		*str;
	size_t		i;
	long long	n2;

	n2 = (long long)n;
	i = ft_intlen(n);
	if (!(str = malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
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
