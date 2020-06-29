/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:15:17 by eboris            #+#    #+#             */
/*   Updated: 2020/03/10 14:04:36 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCT_H
# define MS_STRUCT_H

# include <string.h>
# include "ft_printf.h"
# include "libft.h"
# include "ms_struct_init.h"
# include "ms_path.h"
# include "ms_env_replace.h"

t_set	*ms_create_struct(char **envp);
void	ms_write_struct(t_set *new);
void	ms_del_struct(t_set *new);
void	ms_copy_envp(t_set *new);

#endif
