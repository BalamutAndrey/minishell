/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:34:12 by eboris            #+#    #+#             */
/*   Updated: 2019/10/05 15:22:37 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	i = 0;
	if (s && *s && f)
	{
		while (s[i] != '\0')
		{
			f(&s[i]);
			i++;
		}
	}
}
