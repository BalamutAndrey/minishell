/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:35:59 by eboris            #+#    #+#             */
/*   Updated: 2020/03/05 13:23:25 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSING_H
# define MS_PARSING_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"
# include "ms_parsing_dollar.h"
# include "ms_chdir.h"
# include "ms_echo.h"
# include "ms_run.h"
# include "ms_env.h"
# include "ms_setenv.h"
# include "ms_unsetenv.h"

int		ms_parsing(t_set *new);
char	*ms_corrct_ks(t_set *new, char *ks);
void	ms_corrct_ks_while(char *ks, char *fin, int *i, int *n);

#endif
