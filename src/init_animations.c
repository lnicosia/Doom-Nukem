/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:51 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/03 14:33:26 by lnicosia         ###   ########.fr       */
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
	env->gravity.weight = 1;
	env->jump.on_going = 0;
	env->jump.start = 0;
	env->jump.end = 235;
	env->jump.nb_frame = 15;
	env->squat.on_going = 0;
	env->squat.start = 0;
	env->squat.end = 0;
	env->shot.on_going = 0;
	env->shot.start = 0;
	env->weapon_change.on_going = 0;
	env->weapon_change.start = 0;
}
