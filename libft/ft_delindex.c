/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:08:42 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/26 16:01:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_delindex(void *ptr, size_t old_size, size_t type, size_t index)
{
	void		*res;
	size_t		i;
	size_t		j;
	size_t		new_size;

	if (!ptr || !old_size || !type || old_size <= type)
		return (NULL);
	i = 0;
	j = 0;
	res =  NULL;
	new_size = old_size - type;
	if (!(res = malloc(new_size)))
		return (NULL);
	ft_bzero(res, new_size);
	while (i < new_size)
	{
		if (j == index)
			j += type;
		else
		{
			((char*)res)[i] = ((char*)ptr)[j];
			i++;
			j++;
		}
	}
	ft_memdel(&ptr);
	return (res);
}
