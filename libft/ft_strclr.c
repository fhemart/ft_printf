/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:49:32 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/10 02:04:02 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strclr(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			s[i++] = '\0';
		}
	}
}
