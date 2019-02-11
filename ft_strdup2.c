/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:48:33 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 18:12:53 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup2(t_str *retstr, const char *src)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = malloc(sizeof(char) * ft_strlen(src) + 1)))
	{
		retstr->spec2 = -1;
		return (retstr->bad);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	retstr->spec2 = 0;
	return (dest);
}
