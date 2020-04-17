/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:21:11 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 17:30:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	fps(t_env *env)
{
	Uint32			new_time;

	new_time = SDL_GetTicks();
	env->fps_count++;
	if (new_time - env->frame_timer >= 1000)
	{
		env->frame_timer = new_time;
		env->fps = env->fps_count;
		env->fps_count = 0;
	}
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d", env->fps);
	print_text(new_point(0, 10), new_printable_text(
		env->snprintf, env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	env->sdl.time = new_time;
}
