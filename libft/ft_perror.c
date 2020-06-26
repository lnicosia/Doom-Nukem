/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:37:09 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/19 18:46:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
**	Calls perror with the given string then returns -1
*/

int		ft_perror(const char *s)
{
	perror(s);
	return (-1);
}
