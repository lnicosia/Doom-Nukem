/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:22:49 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 14:56:49 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_keys(t_env *env)
{
	ft_printf("Initializing player keys..\n");
	env->keys.forward = SDLK_w;
	env->keys.s = SDLK_s;
	env->keys.e = SDLK_e;
	env->keys.left = SDLK_a;
	env->keys.right = SDLK_d;
	env->keys.forward2 = SDLK_UP;
	env->keys.backward2 = SDLK_DOWN;
	env->keys.left2 = SDLK_LEFT;
	env->keys.right2 = SDLK_RIGHT;
	env->keys.plus = SDLK_KP_PLUS;
	env->keys.minus = SDLK_KP_MINUS;
	env->keys.shift = SDLK_LSHIFT;
	env->keys.shift2 = SDLK_RSHIFT;
	env->keys.ctrl = SDLK_LCTRL;
	env->keys.space = SDLK_SPACE;
	env->keys.up = SDLK_PAGEUP;
	env->keys.down = SDLK_PAGEDOWN;
	env->keys.option = SDLK_o;
	env->keys.enter = SDLK_RETURN;
	env->keys.backspace = SDLK_BACKSPACE;
	env->keys.del = SDLK_DELETE;
	env->keys.tab = SDLK_TAB;
	env->keys.comma = SDLK_COMMA;
	env->keys.period = SDLK_PERIOD;
	env->keys.minus1 = SDLK_MINUS;
	env->keys.equals = SDLK_EQUALS;
	env->keys.p = SDLK_p;
	env->keys.end = SDLK_END;
	env->keys.home = SDLK_HOME;
	env->keys.a = 'a';
	env->keys.nb1 = SDLK_1;
	env->keys.nb2 = SDLK_2;
	env->keys.nb3 = SDLK_3;
	env->keys.lgui = SDLK_LGUI;
}
