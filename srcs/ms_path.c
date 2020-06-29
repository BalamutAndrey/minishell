/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:09:36 by eboris            #+#    #+#             */
/*   Updated: 2020/06/29 15:42:16 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_path.h"

void	ms_path(t_set *new)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (new->path)
		ms_path_del(new);
	while ((new->cur_envp[i]) &&
			(ft_strncmp(new->cur_envp[i], "PATH=", 5) != 0))
		i++;
	if (new->cur_envp[i])
	{
		temp = ft_strdup(new->cur_envp[i]);
		temp = ft_strmancpy(temp, 5);
		if ((temp) && (temp[0] != '\0'))
			new->path = ms_path_write(temp);
	}
}

void	ms_path_del(t_set *new)
{
	t_path	*temp;
	t_path	*temp2;

	if (new->path)
		temp = new->path;
	else
		temp = NULL;
	while (temp)
	{
		temp2 = temp->next;
		if (temp->path)
			ft_strdel(&temp->path);
		free(temp);
		temp = temp2;
	}
	new->path = NULL;
}

t_path	*ms_path_write(char *param)
{
	t_path	*first;
	t_path	*new;
	t_path	*prev;
	char	*str;
	int		i;

	prev = NULL;
	new = NULL;
	while ((param) && (param[0] != '\0'))
	{
		i = 0;
		while ((param[i] != '\0') && (param[i] != ':'))
			i++;
		if (param[i] == ':')
			str = ft_strmbncpy(param, i);
		else
			str = ft_strdup(param);
		param = ft_strmancpy(param, (i + 1));
		if (new)
			prev = new;
		new = ms_path_write_struct(prev, &first, str);
	}
	ft_strdel(&param);
	return (first);
}

t_path	*ms_path_write_struct(t_path *prev, t_path **first, char *str)
{
	t_path	*new;

	new = malloc(sizeof(t_path));
	new->path = ft_strdup(str);
	ft_strdel(&str);
	new->next = NULL;
	if (prev)
		prev->next = new;
	else
		*first = new;
	ft_strdel(&str);
	return (new);
}
