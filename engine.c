/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:32:37 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 20:26:58 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						finalret(t_str **retstr)
{
	int					ret;

	ret = (*retstr)->len;
	if ((*retstr)->spec2 < 0)
		ret = -1;
	if ((*retstr)->len > 0 && ret != -1)
		write(1, (*retstr)->returnstr, (*retstr)->len);
	free((*retstr)->returnstr);
	free((*retstr)->bad);
	(*retstr)->returnstr = NULL;
	free((*retstr));
	(*retstr) = NULL;
	return (ret);
}

void					skip_garbage(char **ptr, t_str *retstr)
{
	int					z;

	z = 0;
	(retstr->z == 1) ? z++ : z;
	while (ft_strchr("#lhjz", *(*ptr + 1)) && *(*ptr + 1) != '\0')
	{
		(*(*ptr + 1) == '#') ? retstr->diese = 1 : retstr->diese;
		*ptr = *ptr + 1;
	}
	if (retstr->setpre == 1)
	{
		if (retstr->pre < retstr->min_size)
			retstr->z = 0;
		while (!ft_strchr("sSpdDioOuUxXcC%", *(*ptr + 1)) &&
				*(*ptr + 1) != '\0')
		{
			if (*(*ptr + 1) == '+')
				retstr->plus = 1;
			*ptr = *ptr + 1;
		}
		if (ft_strchr("cC%Ssp", *(*ptr + 1)) || *(*ptr + 1) == '\0')
			retstr->z = z;
		if (*(*ptr + 1) == '\0')
			*ptr = *ptr - 2;
	}
}

int						init(t_str **retstr, char *str)
{
	if (!(*retstr = malloc(sizeof(t_str))))
		return (-1);
	if (!((*retstr)->bad = malloc(sizeof(char))))
		return (-1);
	(*retstr)->bad[0] = '\0';
	(*retstr)->min_size = -1;
	(*retstr)->h = 0;
	(*retstr)->hh = 0;
	(*retstr)->l = 0;
	(*retstr)->ll = 0;
	(*retstr)->j = 0;
	(*retstr)->zz = 0;
	(*retstr)->ptrlast = str;
	(*retstr)->spec = 0;
	(*retstr)->spec2 = 0;
	return (0);
}
