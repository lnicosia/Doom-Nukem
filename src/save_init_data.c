/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:07:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 16:07:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	save_init_data(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		env->enemies[i].enemies_init_data.pos = env->enemies[i].pos;
		env->enemies[i].enemies_init_data.health = env->enemies[i].health;
		env->enemies[i].enemies_init_data.sector = env->enemies[i].sector;
		env->enemies[i].enemies_init_data.angle = env->enemies[i].angle;
		env->enemies[i].enemies_init_data.main_sprite = env->enemies[i].main_sprite;
		i++;
	}
	env->player.init_data.pos = env->player.pos;
	env->player.init_data.health = env->player.health;
	env->player.init_data.sector = env->player.sector;
	env->player.init_data.camera = env->player.camera;
	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].object_init_data.main_sprite = env->objects[i].main_sprite;
		env->objects[i].object_init_data.pos = env->objects[i].pos;
		env->objects[i].object_init_data.sector = env->objects[i].sector;
		env->objects[i].object_init_data.angle = env->objects[i].angle;
		i++;
	}
}
