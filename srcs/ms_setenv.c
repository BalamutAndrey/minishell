/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:11:58 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 13:43:31 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_setenv.h"

int		ms_setenv(t_set *new)
{
	int		i;
	char	*temp;
	char	*whats;
	char	*to;

	if (((ms_setenv_check_1(new)) == 0) || ((ms_setenv_check_2(new)) == 0))
		return (0);
	i = 0;
	temp = ft_strdup(new->ks);
	temp = ft_strmancpy(temp, 7);
	temp = ms_setenv_rem_quote(temp);
	while (temp[i] != '\0')
	{
		if (temp[i] == '=')
		{
			whats = ft_strmbncpy(temp, i);
			to = ft_strmancpy(temp, i + 1);
			ms_env_replace(new, whats, to);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ms_setenv_rem_quote(char *str)
{
	int		i;
	int		n;
	char	*fin;

	i = ft_strlen(str);
	fin = ft_strnew(i);
	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '"')
		{
			fin[n] = str[i];
			n++;
		}
		i++;
	}
	fin[n] = '\0';
	ft_strdel(&str);
	return (fin);
}

int		ms_setenv_check_1(t_set *new)
{
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	if (ft_strlen(new->ks) < 10)
	{
		ft_printf("Error! Usage: setenv FOO=bar\n");
		return (0);
	}
	while (new->ks[++i] != '\0')
		if (new->ks[i] == ' ')
			temp++;
	if (temp != 1)
	{
		ft_printf("Error! Usage: setenv FOO=bar\n");
		return (0);
	}
	return (1);
}

int		ms_setenv_check_2(t_set *new)
{
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	while (new->ks[++i] != '\0')
		if (new->ks[i] == '=')
			temp++;
	if (temp != 1)
	{
		ft_printf("Error! Usage: setenv FOO=bar\n");
		return (0);
	}
	return (1);
}
