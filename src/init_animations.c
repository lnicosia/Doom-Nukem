/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:51 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/13 16:44:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_animations2(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		env->enemies[i].death.start = 0;
		env->enemies[i].rest.start = 0;
		env->enemies[i].hurt.start = 0;
		env->enemies[i].pursue.start = 0;
		env->enemies[i].rand_dir.start = 0;
		env->enemies[i].fire.start = 0;
		i++;
	}
	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].rest.start = 0;
		env->objects[i].death.start = 0;
		i++;
	}
}

void	init_animations(t_env *env)
{
	env->time.start = 0;
	env->time.end = 0;
	env->jump.start = 0;
	env->jump.nb_frame = 15;
	env->jump.end = 300;
	env->crouch.on_going = 0;
	env->crouch.start = 0;
	env->crouch.end = 150;
	env->crouch.nb_frame = 6;
	env->crouch.tick = env->crouch.end / env->crouch.nb_frame;
	env->shot.on_going = 0;
	env->shot.start = 0;
	env->player_hurt.start = 0;
	env->weapon_change.on_going = 0;
	env->weapon_change.start = 0;
	init_animations2(env);
}
