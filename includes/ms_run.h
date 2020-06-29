/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:29:15 by eboris            #+#    #+#             */
/*   Updated: 2020/03/05 12:02:35 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_RUN_H
# define MS_RUN_H

# include <sys/stat.h>
# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"
# include "ms_run_argv.h"
# include "ms_env_replace.h"

int		ms_run(t_set *new);
int		ms_run_find(t_set *new);
int		ms_run_access(char *str);
char	*ms_run_write_command(t_set *new, char *str);
int		ms_run_cmd(t_set *new, char *str);

#endif
