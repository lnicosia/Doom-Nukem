/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:51 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/04 15:05:38 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "env.h"

void	init_animations(t_env *env)
{
	int i;

	i = 0;
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
	env->elevator.next_stop = 0;
	env->elevator.on = 0;
	env->elevator.off = 0;
	env->elevator.sector = -1;
	env->elevator.called_from = -1;
	env->elevator.call = 0;
	env->elevator.used = 0;
	env->elevator.speed = 0.01;
	env->elevator.time = 0;
	env->hidden_sect.sector = -1;
	env->hidden_sect.create = 0;
	env->hidden_sect.selected_enemy = -1;
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
}
