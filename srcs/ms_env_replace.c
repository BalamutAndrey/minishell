/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:52:29 by eboris            #+#    #+#             */
/*   Updated: 2020/03/10 14:05:36 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_env_replace.h"

int		ms_env_replace(t_set *new, char *whats, char *to)
{
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen(whats);
	if (len == 0)
		return (0);
	i = -1;
	temp = ft_strdup("=");
	temp = ft_strsdup(whats, temp);
	while (new->cur_envp[++i] != NULL)
	{
		if (ft_strncmp(new->cur_envp[i], temp, len + 1) == 0)
		{
			ft_strdel(&new->cur_envp[i]);
			whats = ft_strdup(temp);
			new->cur_envp[i] = ft_strsdup(whats, to);
			if (ft_strncmp(temp, "PATH=", 5) == 0)
				ms_path(new);
			ft_strdel(&temp);
			return (1);
		}
	}
	ms_env_replace_new(new, temp, to);
	return (1);
}

void	ms_env_replace_new(t_set *new, char *whats, char *to)
{
	char	**env;
	char	*temp;
	int		i;
	int		n;

	i = 0;
	n = ms_env_len(new);
	env = malloc(sizeof(char *) * (n + 2));
	while (new->cur_envp[i] != NULL)
	{
		env[i] = ft_strdup(new->cur_envp[i]);
		i++;
	}
	temp = ft_strdup(whats);
	env[i] = ft_strsdup(whats, to);
	env[i + 1] = NULL;
	if (new->cur_envp)
		ms_env_remove(new);
	new->cur_envp = env;
	if (ft_strncmp(temp, "PATH=", 5) == 0)
		ms_path(new);
	ft_strdel(&temp);
}

void	ms_env_remove(t_set *new)
{
	int	i;

	i = 0;
	while (new->cur_envp[i] != NULL)
	{
		ft_strdel(&new->cur_envp[i]);
		i++;
	}
	free(new->cur_envp);
	new->cur_envp = NULL;
}

int		ms_env_len(t_set *new)
{
	int	i;

	i = 0;
	while (new->cur_envp[i] != NULL)
		i++;
	return (i);
}
