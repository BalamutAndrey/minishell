/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:35:40 by eboris            #+#    #+#             */
/*   Updated: 2020/03/10 15:54:00 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parsing.h"

int		ms_parsing(t_set *new)
{
	new->ks = ms_corrct_ks(new, new->ks);
	if ((ft_strncmp(new->ks, "exit ", 5) == 0) ||
			(ft_strncmp(new->ks, "exit\0", 5) == 0))
		return (0);
	else if ((ft_strncmp(new->ks, "cd ", 3) == 0) ||
			(ft_strncmp(new->ks, "cd\0", 3) == 0))
		ms_chdir(new);
	else if ((ft_strncmp(new->ks, "echo ", 5) == 0) ||
			(ft_strncmp(new->ks, "echo\0", 5) == 0))
		ms_echo(new);
	else if ((ft_strncmp(new->ks, "env ", 4) == 0) ||
			(ft_strncmp(new->ks, "env\0", 4) == 0))
		ms_env(new);
	else if ((ft_strncmp(new->ks, "setenv ", 7) == 0) ||
			(ft_strncmp(new->ks, "setenv\0", 7) == 0))
		ms_setenv(new);
	else if ((ft_strncmp(new->ks, "unsetenv ", 9) == 0) ||
			(ft_strncmp(new->ks, "unsetenv\0", 9) == 0))
		ms_unsetenv(new);
	else if (new->ks[0] != '\0')
		ms_run(new);
	ft_strdel(&new->ks);
	ft_strdel(&new->dir);
	return (1);
}

char	*ms_corrct_ks(t_set *new, char *ks)
{
	int		i;
	int		n;
	char	*fin;

	i = 0;
	n = 0;
	fin = ft_strnew(ft_strlen(ks));
	while ((ks[i] != '\0') && ((ks[i] == ' ') || (ks[i] == '\t')
			|| (ks[i] == '\v') || (ks[i] == '\n')))
		i++;
	while (ks[i] != '\0')
	{
		ms_corrct_ks_while(ks, fin, &i, &n);
	}
	ft_strdel(&ks);
	fin = ms_parsing_dollar(new, fin);
	return (fin);
}

void	ms_corrct_ks_while(char *ks, char *fin, int *i, int *n)
{
	if (((ks[*i] == ' ') || (ks[*i] == '\t')
		|| (ks[*i] == '\v') || (ks[*i] == '\n')) &&
		((ks[*i + 1] == '\0') || (ks[*i + 1] == ' ') || (ks[*i + 1] == '\t')
		|| (ks[*i + 1] == '\v') || (ks[*i + 1] == '\n')))
	{
		*i = *i + 1;
	}
	else
	{
		if ((ks[*i] == ' ') || (ks[*i] == '\t')
				|| (ks[*i] == '\v') || (ks[*i] == '\n'))
		{
			fin[*n] = ' ';
		}
		else
		{
			fin[*n] = ks[*i];
		}
		*i = *i + 1;
		*n = *n + 1;
	}
}
