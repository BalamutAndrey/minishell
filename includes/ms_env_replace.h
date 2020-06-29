/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_replace.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:51:39 by eboris            #+#    #+#             */
/*   Updated: 2020/03/05 13:30:46 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_REPLACE_H
# define MS_ENV_REPLACE_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"
# include "ms_path.h"

int		ms_env_replace(t_set *new, char *whats, char *to);
void	ms_env_replace_new(t_set *new, char *whats, char *to);
void	ms_env_remove(t_set *new);
int		ms_env_len(t_set *new);

#endif
