/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:29:39 by eboris            #+#    #+#             */
/*   Updated: 2020/02/25 15:12:25 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ECHO_H
# define MS_ECHO_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"

int		ms_echo(t_set *new);
char	*ms_echo_quote(char *param);

#endif
