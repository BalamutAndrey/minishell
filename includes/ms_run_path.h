/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_path.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:28:56 by eboris            #+#    #+#             */
/*   Updated: 2020/03/05 09:24:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_RUN_PATH_H
# define MS_RUN_PATH_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct_init.h"

char	*ms_run_write_string(t_set *new, char *str);
char	*ms_run_write_string_point(t_set *new, char *str);
char	*ms_run_write_string_root(t_set *new, char *str);
char	*ms_run_write_string_home(t_set *new, char *str);
char	*ms_run_write_string_other(t_set *new, char *str);

#endif
