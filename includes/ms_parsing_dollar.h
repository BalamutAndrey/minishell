/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing_dollar.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:18:28 by eboris            #+#    #+#             */
/*   Updated: 2020/03/05 11:49:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSING_DOLLAR_H
# define MS_PARSING_DOLLAR_H

# include "ft_printf.h"
# include "libft.h"
# include "ms_struct.h"

char	*ms_parsing_dollar(t_set *new, char *str);
char	*ms_parsing_dollar_write(t_set *new, char *str, int i);
char	*ms_parsing_dollar_build(t_set *new, char *temp1, char *temp2, int n);
char	*ms_parsing_dollar_find(t_set *new, char *str);
int		ms_is_a_space(char c);

#endif
