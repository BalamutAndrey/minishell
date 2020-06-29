/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:22:43 by eboris            #+#    #+#             */
/*   Updated: 2020/03/05 15:15:04 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_unsetenv.h"

int		ms_unsetenv(t_set *new)
{
	char	*temp;
	char	*whats;

	if (ms_unsetenv_check(new) == 0)
		return (0);
	whats = ft_strdup("=");
	temp = ft_strdup(new->ks);
	temp = ft_strmancpy(temp, 9);
	whats = ft_strsdup(temp, whats);
	ms_env_unset(new, whats);
	return (1);
}

void	ms_env_unset(t_set *new, char *whats)
{
	char	**env;
	int		i;
	int		n;

	i = 0;
	n = ms_env_len(new);
	env = malloc(sizeof(char *) * (n + 1));
	n = 0;
	while (new->cur_envp[i] != NULL)
	{
		if (ft_strncmp(new->cur_envp[i], whats, ft_strlen(whats)) != 0)
		{
			env[n] = ft_strdup(new->cur_envp[i]);
			n++;
		}
		i++;
	}
	env[n] = NULL;
	if (new->cur_envp)
		ms_env_remove(new);
	new->cur_envp = env;
	if (ft_strncmp(whats, "PATH=", 5) == 0)
		ms_path(new);
	ft_strdel(&whats);
}

int		ms_unsetenv_check(t_set *new)
{
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	if (ft_strlen(new->ks) < 10)
	{
		ft_printf("Error! Usage: unsetenv FOO\n");
		return (0);
	}
	while (new->ks[++i] != '\0')
		if (new->ks[i] == ' ')
			temp++;
	if (temp != 1)
	{
		ft_printf("Error! Usage: unsetenv FOO\n");
		return (0);
	}
	return (1);
}
