/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:14 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/08 14:41:11 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

static void	write_object(int fd, t_object object)
{
	ft_dprintf(fd, "[%.3f %.3f %.3f %.3f] ",
			object.pos.y, object.pos.x, object.pos.z, object.angle);
	ft_dprintf(fd, "[%d %.f]\n",
			object.sprite, object.scale);
}

void		write_objects(int fd, t_env *env)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "\nO %d\n", env->nb_objects);
	while (i < env->nb_objects)
	{
		write_object(fd, env->objects[i]);
		i++;
	}
}
