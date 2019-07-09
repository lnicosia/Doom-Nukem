/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:51 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/09 13:45:16 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.h"

void	init_animations(t_env *env)
{
	env->time.start = 0;
	env->time.end = 0;
	env->player.state = 0;
	env->gravity.on_going = 1;
	env->gravity.start = 0;
	env->gravity.end = 0;
	env->gravity.weight = 0;
	env->jump.on_going = 0;
	env->jump.start = 0;
	env->jump.nb_frame = 8;
	env->jump.end = 300;
	env->crouch.on_going = 0;
	env->crouch.start = 0;
	env->crouch.end = 150;
	env->crouch.nb_frame = 6;
	env->crouch.tick = env->crouch.end / env->crouch.nb_frame;
	env->shot.on_going = 0;
	env->shot.start = 0;
	env->weapon_change.on_going = 0;
	env->weapon_change.start = 0;
}
