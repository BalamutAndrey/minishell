/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:24:14 by eboris            #+#    #+#             */
/*   Updated: 2020/03/10 15:39:04 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parsing_dollar.h"

char	*ms_parsing_dollar(t_set *new, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ms_is_a_space(str[i]))
		{
			if (str[i + 1] == '$')
			{
				str = ms_parsing_dollar_write(new, str, i);
				i = 0;
			}
		}
		i++;
	}
	return (str);
}

char	*ms_parsing_dollar_write(t_set *new, char *str, int i)
{
	int		n;
	char	*temp1;
	char	*temp2;

	n = 0;
	temp1 = ft_strmbncpy(str, i + 1);
	temp2 = ft_strmancpy(str, i + 1);
	while (temp2[n] != '\0')
	{
		if ((temp2[n] != '\0') && (ms_is_a_space(temp2[n])))
		{
			str = ms_parsing_dollar_build(new, temp1, temp2, n);
			return (str);
		}
		n++;
	}
	str = ms_parsing_dollar_build(new, temp1, temp2, n);
	return (str);
}

char	*ms_parsing_dollar_build(t_set *new, char *temp1, char *temp2, int n)
{
	char	*temp3;
	char	*str;

	temp3 = ft_strmbncpy(temp2, n);
	str = ft_strmancpy(temp2, n);
	temp3 = ms_parsing_dollar_find(new, temp3);
	temp3 = ft_strsdup(temp1, temp3);
	str = ft_strsdup(temp3, str);
	return (str);
}

char	*ms_parsing_dollar_find(t_set *new, char *str)
{
	int		i;
	int		n;
	char	*temp;
	char	*temp2;

	i = 0;
	temp = ft_strdup("=");
	temp = ft_strsdup(str, temp);
	temp = ft_strmancpy(temp, 1);
	n = ft_strlen(temp);
	while (new->cur_envp[i] != NULL)
	{
		if (ft_strncmp(new->cur_envp[i], temp, n) == 0)
		{
			ft_strdel(&temp);
			temp2 = ft_strdup(new->cur_envp[i]);
			temp = ft_strmancpy(temp2, n);
			return (temp);
		}
		i++;
	}
	ft_strdel(&temp);
	temp = ft_strdup(" ");
	return (temp);
}

int		ms_is_a_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}
