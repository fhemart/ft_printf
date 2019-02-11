/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:31:24 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:46:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_strrjoin(t_str *retstr, char *s1, char *s2, char **dest)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	tmp1 = ft_strdup2(retstr, s1);
	tmp2 = ft_strdup2(retstr, s2);
	tmp3 = ft_strdup2(retstr, *dest);
	free(*dest);
	*dest = NULL;
	*dest = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	free(tmp3);
}
