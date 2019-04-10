/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:46:04 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/09 15:26:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i);
		i++;
	}
	return (0);
}

static size_t	ft_get_end(char const *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i);
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (0);
	start = ft_get_start(s);
	end = ft_get_end(s);
	if (!(str = ft_strnew(end - start + 1)))
		return (0);
	if (end - start == 0)
		return (str);
	while (i < start)
	{
		i++;
		s++;
	}
	if (!(str = ft_strncpy(str, s, end - start + 1)))
		return (0);
	return (str);
}
