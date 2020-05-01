/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_vertices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:50:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 12:19:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

void	write_vertices(int fd, t_env *env)
{
	int	i;
	int	size;
	int	padding;

	ft_dprintf(fd, "V %d\n", env->nb_vertices);
	size = 0;
	padding = 0;
	i = 0;
	while (i < env->nb_vertices)
	{
		size = ft_max(ft_getsize(env->vertices[i].y),
		ft_getsize(env->vertices[i].x));
		if (size > padding)
			padding = size;
		i++;
	}
	i = 0;
	while (i < env->nb_vertices)
	{
		ft_dprintf(fd, "%.*f %.*f\n",
		ft_min(5, get_decimal_len(env->vertices[i].y)), env->vertices[i].y,
		ft_min(5, get_decimal_len(env->vertices[i].x)), env->vertices[i].x);
		i++;
	}
}
