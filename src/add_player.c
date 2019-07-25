/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:58:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/25 17:34:10 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	add_player(t_env *env)
{
	env->edit.player.x = (env->sdl.mx - env->edit.center.x) / env->edit.scale;
	env->edit.player.y = (env->sdl.my - env->edit.center.y) / env->edit.scale;
	env->edit.player.z = 0;
	env->edit.player. angle = 0;
	env->edit.new_player = 2;
}
