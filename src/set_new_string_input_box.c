/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_string_input_box.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:40:04 by marvin            #+#    #+#             */
/*   Updated: 2020/05/19 16:40:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		set_new_string_input_box(t_input_box *box, void *target)
{
	box->str_target = (char**)target;
	if (box->str)
		ft_strdel(&box->str);
	if (*(char**)target)
	{
		if (!(box->str = ft_strdup(*(char**)target))
			&& ft_strlen(*(char**)target))
			return (-1);
	}
	else
	{
		if (!(box->str = ft_strnew(0)))
			return (-1);
	}
	return (0);
}
