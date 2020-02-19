/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:14 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 17:53:30 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

static void	write_object(int fd, t_object object, t_env *env)
{
	ft_dprintf(fd, "[%.*f %.*f %.*f %.*f] ",
			ft_min(5, get_decimal_len(object.pos.y)),
			object.pos.y,
			ft_min(5, get_decimal_len(object.pos.x)),
			object.pos.x,
			ft_min(5, get_decimal_len(object.pos.z)),
			object.pos.z,
			ft_min(5, get_decimal_len(object.angle)),
			object.angle);
	ft_dprintf(fd, "[%d %.*f]\n",
			get_main_sprite(object.sprite, env),
			ft_min(5, get_decimal_len(object.scale)),
			object.scale);
}

void		write_objects(int fd, t_env *env)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "\nO %d\n", env->nb_objects);
	while (i < env->nb_objects)
	{
		write_object(fd, env->objects[i], env);
		i++;
	}
}
