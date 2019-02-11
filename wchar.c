/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:32:06 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/22 00:38:55 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					bit6(wchar_t wchar)
{
	size_t			i;
	unsigned int	oct;

	i = 0;
	oct = 0;
	while (i < 6)
	{
		if (((unsigned int)wchar & (1 << i)) != 0)
			oct = oct | (1 << i);
		i++;
	}
	return (oct | 128);
}

size_t				wcharlen(t_str *retstr, wchar_t wchar)
{
	size_t			len;
	char			*bin;

	bin = convertbase10(retstr, wchar, 2);
	len = ft_strlen(bin);
	free(bin);
	if (len <= 7)
		return (1);
	else if (len <= 11)
		return (2);
	else if (len > 11 && len <= 16)
		return (3);
	else
		return (4);
}

size_t				strwcharlen(t_str *retstr, wchar_t *strw)
{
	size_t			len;
	size_t			i;

	len = 0;
	i = 0;
	while (strw[i] != '\0')
	{
		len = len + wcharlen(retstr, strw[i]);
		i++;
	}
	return (len);
}

int					firstoct(wchar_t wchar, size_t len)
{
	if (len == 2)
		return (wchar | 192);
	if (len == 3)
		return (wchar | 224);
	if (len == 4)
		return (wchar | 240);
	else
		return (0);
}

char				*lastoct(t_str *retstr, wchar_t wchar)
{
	char			*str;
	size_t			len;
	size_t			i;

	str = ft_strnew2(retstr, 4);
	len = wcharlen(retstr, wchar);
	i = 0;
	while (len != 1)
	{
		str[len - 1] = bit6(wchar);
		wchar = wchar >> 6;
		len--;
		i++;
	}
	str[0] = firstoct(wchar, i + 1);
	return (str);
}
