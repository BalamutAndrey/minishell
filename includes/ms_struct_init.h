/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_struct_init.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:29:16 by eboris            #+#    #+#             */
/*   Updated: 2020/02/25 16:30:02 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCT_INIT_H
# define MS_STRUCT_INIT_H

typedef struct		s_path
{
	char			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_set
{
	char			**envp;
	char			**cur_envp;
	char			*dir;
	char			*oldpwd;
	char			*ks;
	char			*user;
	char			*home;
	t_path			*path;
}					t_set;

#endif
