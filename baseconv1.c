/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseconv1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:44:09 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:49:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*sconvertbase10(t_str *retstr, unsigned short nb, int base)
{
	char			*str;
	char			*tmp;
	char			*ptr;
	char			*baserep;

	baserep = "0123456789abcdef";
	tmp = ft_strnew2(retstr, 50);
	ptr = &tmp[49];
	while (nb != 0)
	{
		*--ptr = baserep[nb % base];
		nb = nb / base;
	}
	if (ft_strlen(ptr) > 0)
		str = ft_strdup2(retstr, ptr);
	else
	{
		str = ft_strnew2(retstr, 1);
		str[0] = '0';
	}
	free(tmp);
	return (str);
}

char				*cconvertbase10(t_str *retstr, int nb, int base)
{
	char			*str;
	char			*tmp;
	char			*ptr;
	char			*baserep;

	baserep = "0123456789abcdef";
	if ((nb > 255 && nb < 65534) || nb < 0)
		nb = (unsigned char)nb;
	tmp = ft_strnew2(retstr, 50);
	ptr = &tmp[49];
	while (nb != 0)
	{
		*--ptr = baserep[nb % base];
		nb = nb / base;
	}
	if (ft_strlen(ptr) > 0)
		str = ft_strdup2(retstr, ptr);
	else
	{
		str = ft_strnew2(retstr, 1);
		str[0] = '0';
	}
	free(tmp);
	return (str);
}

char				*imconvertbase10(t_str *retstr, uintmax_t nb, int base)
{
	char			*str;
	char			*tmp;
	char			*ptr;
	char			*baserep;

	baserep = "0123456789abcdef";
	tmp = ft_strnew2(retstr, 50);
	ptr = &tmp[49];
	while (nb != 0)
	{
		*--ptr = baserep[nb % base];
		nb = nb / base;
	}
	if (ft_strlen(ptr) > 0)
		str = ft_strdup2(retstr, ptr);
	else
	{
		str = ft_strnew2(retstr, 1);
		str[0] = '0';
	}
	free(tmp);
	return (str);
}

char				*stconvertbase10(t_str *retstr, size_t nb, int base)
{
	char			*str;
	char			*tmp;
	char			*ptr;
	char			*baserep;

	baserep = "0123456789abcdef";
	tmp = ft_strnew2(retstr, 50);
	ptr = &tmp[49];
	while (nb != 0)
	{
		*--ptr = baserep[nb % base];
		nb = nb / base;
	}
	if (ft_strlen(ptr) > 0)
		str = ft_strdup2(retstr, ptr);
	else
	{
		str = ft_strnew2(retstr, 1);
		str[0] = '0';
	}
	free(tmp);
	return (str);
}

char				*llconvertbase10(t_str *retstr, uintmax_t nb, int base)
{
	char			*str;
	char			*tmp;
	char			*ptr;
	char			*baserep;

	baserep = "0123456789abcdef";
	tmp = ft_strnew2(retstr, 50);
	ptr = &tmp[49];
	while (nb != 0)
	{
		*--ptr = baserep[nb % base];
		nb = nb / base;
	}
	if (ft_strlen(ptr) > 0)
		str = ft_strdup2(retstr, ptr);
	else
	{
		str = ft_strnew2(retstr, 1);
		str[0] = '0';
	}
	free(tmp);
	return (str);
}
