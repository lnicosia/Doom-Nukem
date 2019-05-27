/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:51 by sipatry           #+#    #+#             */
/*   Updated: 2019/05/24 11:45:56 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.h"

void	init_animations(t_env *env)
{
	env->gravity.on_going = 1;
	env->jump.on_going = 0;
	env->jump.start = 0;
	env->jump.end = 0;
	env->squat.on_going = 0;
	env->squat.start = 0;
	env->squat.end = 0;
}
