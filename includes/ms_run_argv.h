/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_argv.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:56:43 by eboris            #+#    #+#             */
/*   Updated: 2020/03/05 12:02:08 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_RUN_ARGV_H
# define MS_RUN_ARGV_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"

char	**ms_run_argv(char *path, char *ks);
int		ms_strsplit_words(char *ks);
void	ms_strsplit(char **argv, char *ks);
void	ms_run_argv_remove(char **argv);

#endif
