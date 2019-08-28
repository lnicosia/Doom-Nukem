/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:18:24 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/19 14:45:08 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void		*res;

	if (old_size == new_size)
		return (ptr);
	if (!(res = malloc(new_size)))
		return (NULL);
	ft_bzero(res, new_size);
	if (ptr)
	{
		res = ft_memmove(res, ptr, old_size);
	}
	ft_memdel(&ptr);
	return (res);
}
