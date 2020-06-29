/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:10:24 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 14:23:18 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SETENV_H
# define MS_SETENV_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"
# include "ms_env_replace.h"

int		ms_setenv(t_set *new);
char	*ms_setenv_rem_quote(char *str);
int		ms_setenv_check_1(t_set *new);
int		ms_setenv_check_2(t_set *new);

#endif
