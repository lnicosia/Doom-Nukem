/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:35:51 by sipatry           #+#    #+#             */
/*   Updated: 2019/06/04 15:24:36 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.h"

void	init_animations(t_env *env)
{
	ft_printf("coucou\n");
	env->player.state = 0;
	env->gravity.on_going = 1;
	env->gravity.start = 0;
	env->gravity.end = 0;
	env->gravity.weight = 1;
	env->jump.on_going = 0;
	env->jump.start = 0;
	env->jump.end = 0;
	env->squat.on_going = 0;
	env->squat.start = 0;
	env->squat.end = 0;
}
