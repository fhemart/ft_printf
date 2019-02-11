/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_S.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:17:29 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/21 21:46:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		wcharstrloop(t_str *retstr, char **str, wchar_t *tmp)
{
	char		*strtmp;
	size_t		i;

	*str = ft_strnew2(retstr, 0);
	i = 0;
	while (tmp[i] != '\0')
	{
		if (wcharlen(retstr, tmp[i]) == 1)
		{
			strtmp = ft_strnew2(retstr, 1);
			strtmp[0] = (char)tmp[i];
			ft_strrjoin(retstr, *str, strtmp, str);
		}
		else
		{
			strtmp = lastoct(retstr, tmp[i]);
			ft_strrjoin(retstr, *str, strtmp, str);
		}
		free(strtmp);
		i++;
	}
}

char			*flag_ss(va_list arg, char *ptr, t_str *retstr)
{
	char			*str;
	char			*strfinal;
	wchar_t			*tmp;

	retstr->space = 0;
	if ((tmp = va_arg(arg, wchar_t *)) == NULL)
		str = ft_strdup2(retstr, "(null)");
	else
		wcharstrloop(retstr, &str, tmp);
	if (retstr->pre < (int)ft_strlen(str) && retstr->pre > 0)
	{
		strfinal = ft_strsub(str, 0, retstr->pre);
		if ((strfinal[retstr->pre - 1] & 1 << 6) != 0
				&& strfinal[retstr->pre - 1] < 0)
			strfinal[retstr->pre - 1] = '\0';
	}
	else
		strfinal = ft_strdup2(retstr, str);
	retstr->ptrlast = ptr + 2;
	if (retstr->setpre == 1 && retstr->pre == 0)
		formatpre(&strfinal, retstr);
	formatstr(&strfinal, retstr);
	free(str);
	return (strfinal);
}

char			*flag_s(va_list arg, char *ptr, t_str *retstr)
{
	char		*str;
	char		*tmp;

	retstr->space = 0;
	if (retstr->l == 1)
	{
		str = flag_ss(arg, ptr, retstr);
		tmp = NULL;
		return (str);
	}
	if ((tmp = va_arg(arg, char *)) == NULL)
		str = ft_strdup2(retstr, "(null)");
	else if (retstr->pre < (int)ft_strlen(tmp) && retstr->pre > 0)
		str = ft_strsub(tmp, 0, retstr->pre);
	else
		str = ft_strdup2(retstr, tmp);
	retstr->ptrlast = ptr + 2;
	if (retstr->setpre == 1 && retstr->pre == 0)
		formatpre(&str, retstr);
	formatstr(&str, retstr);
	return (str);
}
