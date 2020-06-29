/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:30:43 by eboris            #+#    #+#             */
/*   Updated: 2020/03/04 17:46:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_echo.h"

int		ms_echo(t_set *new)
{
	char	*param;

	param = ft_strdup(new->ks);
	param = ft_strmancpy(param, 5);
	param = ms_echo_quote(param);
	ft_printf("%s\n", param);
	ft_strdel(&param);
	return (1);
}

char	*ms_echo_quote(char *param)
{
	int		i;
	int		n;
	char	*fin;

	i = 0;
	n = 0;
	fin = ft_strnew(ft_strlen(param));
	while (param[i] != '\0')
	{
		if (param[i] != '"')
		{
			fin[n] = param[i];
			n++;
		}
		i++;
	}
	ft_strdel(&param);
	return (fin);
}
