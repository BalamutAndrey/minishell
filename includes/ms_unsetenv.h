/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:16:23 by eboris            #+#    #+#             */
/*   Updated: 2020/03/05 13:55:54 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_UNSETENV_H
# define MS_UNSETENV_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"
# include "ms_env_replace.h"

int		ms_unsetenv(t_set *new);
void	ms_env_unset(t_set *new, char *whats);
int		ms_unsetenv_check(t_set *new);

#endif
