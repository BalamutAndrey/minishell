/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:08:44 by eboris            #+#    #+#             */
/*   Updated: 2020/03/04 18:29:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PATH_H
# define MS_PATH_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct_init.h"
# include "ms_run_path.h"

void	ms_path(t_set *new);
void	ms_path_del(t_set *new);
t_path	*ms_path_write(char *param);
t_path	*ms_path_write_struct(t_path *prev, t_path **first, char *str);

#endif
