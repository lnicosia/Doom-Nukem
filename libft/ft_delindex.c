/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:08:42 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 18:58:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	fill_current_index(void *res, void *ptr, size_t *i, size_t *j)
{
	((char*)res)[*i] = ((char*)ptr)[*j];
	(*i)++;
	(*j)++;
}

void	*ft_delindex(void *ptr, size_t old_size, size_t type, size_t index)
{
	void		*res;
	size_t		i;
	size_t		j;
	size_t		new_size;

	if (!ptr || !old_size || !type || old_size < type)
		return (NULL);
	i = 0;
	j = 0;
	new_size = old_size - type;
	if (new_size == 0 || !(res = malloc(new_size)))
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	ft_bzero(res, new_size);
	while (i < new_size)
	{
		if (j == index)
			j += type;
		else
			fill_current_index(res, ptr, &i, &j);
	}
	ft_memdel(&ptr);
	return (res);
}
