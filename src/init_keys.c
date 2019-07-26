/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:22:49 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/26 11:23:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_keys(t_env *env)
{
	ft_printf("Initializing player keys..\n");
	env->keys.forward = SDLK_w;
	env->keys.backward = SDLK_s;
	env->keys.left = SDLK_a;
	env->keys.right = SDLK_d;
	env->keys.forward2 = SDLK_UP;
	env->keys.backward2 = SDLK_DOWN;
	env->keys.left2 = SDLK_LEFT;
	env->keys.right2 = SDLK_RIGHT;
	env->keys.plus = SDLK_KP_PLUS;
	env->keys.minus = SDLK_KP_MINUS;
	env->keys.shift = SDLK_LSHIFT;
	env->keys.ctrl = SDLK_LCTRL;
	env->keys.space = SDLK_SPACE;
	env->keys.up = SDLK_PAGEUP;
	env->keys.down = SDLK_PAGEDOWN;
	env->keys.option = SDLK_o;
}
