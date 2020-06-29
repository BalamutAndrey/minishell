/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:30:22 by eboris            #+#    #+#             */
/*   Updated: 2020/03/10 14:58:16 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_run_path.h"

char	*ms_run_write_string(t_set *new, char *str)
{
	char	*str2;

	if (new->ks[0] == '.')
	{
		str2 = ms_run_write_string_point(new, str);
	}
	else if (new->ks[0] == '/')
	{
		str2 = ms_run_write_string_root(new, str);
	}
	else if (new->ks[0] == '~')
	{
		str2 = ms_run_write_string_home(new, str);
	}
	else
	{
		str2 = ms_run_write_string_other(new, str);
	}
	return (str2);
}

char	*ms_run_write_string_point(t_set *new, char *str)
{
	char	*str1;
	char	*str2;

	str2 = ft_strdup(new->dir);
	str1 = ft_strdup("/");
	str2 = ft_strsdup(str2, str1);
	str1 = ft_strdup(new->ks);
	str2 = ft_strsdup(str2, str1);
	(void)str;
	return (str2);
}

char	*ms_run_write_string_root(t_set *new, char *str)
{
	char	*str2;

	str2 = ft_strdup(new->ks);
	(void)str;
	return (str2);
}

char	*ms_run_write_string_home(t_set *new, char *str)
{
	char	*str1;
	char	*str2;

	str2 = ft_strdup(new->ks);
	str2 = ft_strmancpy(str2, 1);
	str1 = ft_strdup(new->home);
	str2 = ft_strsdup(str1, str2);
	(void)str;
	return (str2);
}

char	*ms_run_write_string_other(t_set *new, char *str)
{
	char	*str1;
	char	*str2;

	str2 = ft_strdup(str);
	str1 = ft_strdup("/");
	str2 = ft_strsdup(str2, str1);
	str1 = ft_strdup(new->ks);
	str2 = ft_strsdup(str2, str1);
	(void)str;
	return (str2);
}
