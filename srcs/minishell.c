/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:17:17 by eboris            #+#    #+#             */
/*   Updated: 2020/03/10 15:55:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_set	*new;
	int		ks_len;
	int		finish;

	finish = 1;
	new = ms_create_struct(envp);
	(void)argc;
	(void)argv;
	while (finish != 0)
	{
		new->dir = ft_strnew(256);
		new->ks = ft_strnew(256);
		getcwd(new->dir, 255);
		if (new->user)
			ft_printf("%s", new->user);
		ft_printf("$> ");
		ks_len = read(1, new->ks, 255);
		new->ks[ks_len - 1] = '\0';
		finish = ms_parsing(new);
	}
	ms_del_struct(new);
	free(new);
	return (0);
}
