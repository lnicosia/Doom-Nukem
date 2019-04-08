/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:12:02 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/21 14:59:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	if (!(str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (0);
	if (!(str = ft_strcpy(str, s1)))
		return (0);
	if (!(str = ft_strcat(str, s2)))
		return (0);
	if (!s1 || !s2)
		return (0);
	return (str);
}
