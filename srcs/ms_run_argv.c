/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:57:29 by eboris            #+#    #+#             */
/*   Updated: 2020/06/29 16:12:16 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_run_argv.h"

char	**ms_run_argv(char *path, char *ks)
{
	char	**argv;
	int		n;

	n = ms_strsplit_words(ks);
	argv = malloc(sizeof(char *) * (n + 2));
	argv[0] = ft_strdup(path);
	if (n > 0)
	{
		ms_strsplit(argv, ks);
	}
	else
	{
		argv[1] = NULL;
		ft_strdel(&ks);
	}
	return (argv);
}

int		ms_strsplit_words(char *ks)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (ks[i] != '\0')
	{
		if (ks[i] == ' ')
			n++;
		i++;
	}
	return (n);
}

void	ms_strsplit(char **argv, char *ks)
{
	int		i;
	int		n;
	int		temp;

	temp = 0;
	n = 0;
	while (ks[0] != '\0')
	{
		i = 0;
		while ((ks[i] != '\0') && (ks[i] != ' '))
			i++;
		if (i > 0)
		{
			if (temp == 0)
				temp = 1;
			else
				argv[n] = ft_strmbncpy(ks, i);
			ks = ft_strmancpy(ks, i + 1);
		}
		n++;
	}
	ft_strdel(&ks);
	argv[n] = NULL;
}

void	ms_run_argv_remove(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i] != NULL)
		{
			ft_strdel(&argv[i]);
			i++;
		}
		free(argv);
		argv = NULL;
	}
}
