/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_chdir.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:19 by eboris            #+#    #+#             */
/*   Updated: 2020/03/04 20:25:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_CHDIR_H
# define MS_CHDIR_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"
# include "ms_env_replace.h"

int		ms_chdir(t_set *new);
void	ms_chdir_finish(t_set *new, char *param, char *temp_param);
char	*ms_home_dir(t_set *new, char *param);
char	*ms_prev_dir(t_set *new, char *param);
char	*ms_no_root_dir(t_set *new, char *param);

#endif
