/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:24:44 by eboris            #+#    #+#             */
/*   Updated: 2020/06/29 15:36:03 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_struct.h"

t_set	*ms_create_struct(char **envp)
{
	t_set	*new;

	new = malloc(sizeof(t_set));
	new->envp = envp;
	new->cur_envp = NULL;
	new->dir = NULL;
	new->oldpwd = NULL;
	new->ks = NULL;
	new->home = NULL;
	new->path = NULL;
	new->user = NULL;
	ms_write_struct(new);
	ms_copy_envp(new);
	ms_path(new);
	return (new);
}

void	ms_write_struct(t_set *new)
{
	int		i;
	char	*temp;

	i = -1;
	while (new->envp[++i])
		if (ft_strncmp(new->envp[i], "HOME=", 5) == 0)
		{
			temp = ft_strdup(new->envp[i]);
			new->home = ft_strmancpy(temp, 5);
		}
		else if (ft_strncmp(new->envp[i], "USER=", 5) == 0)
		{
			temp = ft_strdup(new->envp[i]);
			new->user = ft_strmancpy(temp, 5);
		}
		else if (ft_strncmp(new->envp[i], "OLDPWD=", 7) == 0)
		{
			temp = ft_strdup(new->envp[i]);
			new->oldpwd = ft_strmancpy(temp, 7);
		}
}

void	ms_del_struct(t_set *new)
{
	ft_strdel(&new->dir);
	ft_strdel(&new->oldpwd);
	ft_strdel(&new->ks);
	ft_strdel(&new->home);
	ft_strdel(&new->user);
	if (new->path != NULL)
		ms_path_del(new);
	ms_env_remove(new);
	new->path = NULL;
}

void	ms_copy_envp(t_set *new)
{
	int		i;
	char	**cur_envp;

	i = 0;
	while (new->envp[i])
		i++;
	cur_envp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (new->envp[i])
	{
		cur_envp[i] = ft_strnew(ft_strlen(new->envp[i]));
		cur_envp[i] = ft_strcpy(cur_envp[i], new->envp[i]);
		i++;
	}
	new->cur_envp = cur_envp;
	i = 0;
}
