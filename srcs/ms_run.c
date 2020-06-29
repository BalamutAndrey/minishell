/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:30:21 by eboris            #+#    #+#             */
/*   Updated: 2020/03/10 15:02:28 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_run.h"

int		ms_run(t_set *new)
{
	char	*str;
	char	*temp;

	temp = ft_strdup(new->ks);
	if ((!temp) || (temp[0] == '\0'))
		return (0);
	str = ms_run_write_string(new, temp);
	ft_strdel(&temp);
	str = ms_run_write_command(new, str);
	if ((str) && (str[0] != '\0'))
	{
		if ((!access(str, 0)) && (!access(str, 1)) && (ms_run_access(str)))
		{
			ms_run_cmd(new, str);
		}
		else
		{
			ms_run_find(new);
		}
	}
	ft_strdel(&str);
	return (1);
}

int		ms_run_find(t_set *new)
{
	t_path	*temp;
	char	*str;
	int		i;

	temp = new->path;
	i = 0;
	while (temp)
	{
		str = ms_run_write_string(new, temp->path);
		str = ms_run_write_command(new, str);
		if ((!access(str, 0)) && (!access(str, 1)) && (ms_run_access(str)))
		{
			ms_run_cmd(new, str);
			i = 1;
			temp = NULL;
		}
		else
			temp = temp->next;
		ft_strdel(&str);
	}
	if (i == 0)
		ft_printf("minishell: command not found: %s\n", new->ks);
	return (1);
}

int		ms_run_access(char *str)
{
	int			i;
	struct stat	buff;

	i = 0;
	lstat(str, &buff);
	if (!(S_ISLNK(buff.st_mode)) && !(S_ISREG(buff.st_mode)))
		return (0);
	if (!(S_ISLNK(buff.st_mode)))
		stat(str, &buff);
	if ((buff.st_mode & S_IXUSR) || (buff.st_mode & S_IXGRP) ||
			(buff.st_mode & S_IXOTH))
		return (1);
	return (0);
}

char	*ms_run_write_command(t_set *new, char *str)
{
	int		n;
	char	*fin;

	n = 0;
	while ((str[n] != '\0') && (str[n] != ' '))
		n++;
	fin = ft_strmbncpy(str, n);
	ft_strdel(&str);
	(void)new;
	return (fin);
}

int		ms_run_cmd(t_set *new, char *str)
{
	int		status;
	char	*temp1;
	char	*temp2;
	char	**argv;
	pid_t	pid;

	temp1 = ft_strdup(new->ks);
	argv = ms_run_argv(str, temp1);
	pid = fork();
	if (pid == 0)
		execve(argv[0], argv, new->cur_envp);
	else if (pid < 0)
		ft_printf("Error!\n");
	waitpid(pid, &status, 0);
	temp1 = ft_strdup("_");
	temp2 = ft_strdup(argv[0]);
	ms_env_replace(new, temp1, temp2);
	ms_run_argv_remove(argv);
	return (1);
}
