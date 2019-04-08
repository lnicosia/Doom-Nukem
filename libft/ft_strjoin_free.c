/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:12:02 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/21 15:41:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	if (!(str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (0);
	if (!(ft_strcpy(str, s1)))
		return (0);
	if (!(ft_strcat(str, s2)))
		return (0);
	ft_strdel(&s1);
	return (str);
}
