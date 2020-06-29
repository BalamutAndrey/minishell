/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:49:26 by eboris            #+#    #+#             */
/*   Updated: 2020/03/10 14:09:09 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_chdir.h"

int		ms_chdir(t_set *new)
{
	char	*param;
	char	*temp_param;

	param = ft_strdup(new->ks);
	param = ft_strmancpy(param, 3);
	temp_param = ft_strdup(param);
	if (param[0] != '\0')
	{
		if (param[0] == '~')
			param = ms_home_dir(new, param);
		else if ((param[0] == '-') && (param[1] == '\0'))
			param = ms_prev_dir(new, param);
		else if (param[0] != '/')
			param = ms_no_root_dir(new, param);
	}
	else
	{
		ft_strdel(&param);
		param = ft_strdup(new->home);
	}
	ms_chdir_finish(new, param, temp_param);
	return (1);
}

void	ms_chdir_finish(t_set *new, char *param, char *temp_param)
{
	int		fin;
	char	*temp1;
	char	*temp2;

	fin = chdir(param);
	if (fin != 0)
		ft_printf("cd: no such file or directory: %s\n", temp_param);
	else
	{
		ft_strdel(&new->oldpwd);
		new->oldpwd = ft_strdup(new->dir);
		temp1 = ft_strdup("OLDPWD");
		temp2 = ft_strdup(new->dir);
		ms_env_replace(new, temp1, temp2);
		ft_strdel(&new->dir);
		new->dir = ft_strnew(256);
		getcwd(new->dir, 255);
		temp1 = ft_strdup("PWD");
		temp2 = ft_strdup(new->dir);
		ms_env_replace(new, temp1, temp2);
	}
	ft_strdel(&param);
	ft_strdel(&temp_param);
}

char	*ms_home_dir(t_set *new, char *param)
{
	char	*fin;
	char	*temp;

	fin = ft_strmancpy(param, 1);
	temp = ft_strdup(new->home);
	fin = ft_strsdup(temp, fin);
	return (fin);
}

char	*ms_prev_dir(t_set *new, char *param)
{
	int		i;
	char	*fin;

	i = 0;
	if (new->oldpwd)
		fin = ft_strdup(new->oldpwd);
	else
		fin = ft_strdup(new->home);
	ft_printf("%s\n", fin);
	ft_strdel(&param);
	return (fin);
}

char	*ms_no_root_dir(t_set *new, char *param)
{
	char	*fin;
	char	*temp;
	char	*temp2;

	temp = ft_strdup("/");
	temp2 = ft_strdup(new->dir);
	temp = ft_strsdup(temp2, temp);
	fin = ft_strsdup(temp, param);
	return (fin);
}
