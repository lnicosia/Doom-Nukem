/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_vertices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:50:17 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 12:29:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

void	write_vertices(int fd, t_env *env)
{
	int	i;

	ft_dprintf(fd, "V %d\n", env->nb_vertices);
	i = 0;
	while (i < env->nb_vertices)
	{
		ft_dprintf(fd, "%.f %.f\n", env->vertices[i].y, env->vertices[i].x);
		i++;
	}
}
