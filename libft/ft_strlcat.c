/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 20:11:49 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/09 15:25:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = size;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	while (*dst)
	{
		dst++;
		if (i > 0)
			i--;
	}
	while (*src && i > 1)
	{
		*dst = *src;
		src++;
		dst++;
		i--;
	}
	*dst = '\0';
	if (size > dstlen)
		return (srclen + dstlen);
	return (size + srclen);
}
