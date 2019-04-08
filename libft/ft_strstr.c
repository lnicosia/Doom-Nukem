/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:15:03 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/09 15:25:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char*)haystack);
	while (haystack[i])
	{
		if (needle[0] == haystack[i])
		{
			j = 0;
			while (needle[j] == haystack[i + j] && needle[j])
			{
				j++;
			}
			if (!needle[j])
				return ((char*)haystack + i);
		}
		i++;
	}
	return (0);
}
