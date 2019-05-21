/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:30 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/16 14:31:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	options(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_c)
		env->options.contouring = env->options.contouring ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_r)
		env->options.render_sectors = env->options.render_sectors ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_l)
		env->options.lighting = env->options.lighting ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_m)
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_f)
		env->options.show_fps = env->options.show_fps ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_x)
		env->options.wall_lover = env->options.wall_lover ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_j)
		env->options.color_clipping = env->options.color_clipping ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_g)
		env->options.wall_color = env->options.wall_color ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_t)
		env->options.test = env->options.test ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_i)
		env->options.clipping = env->options.clipping ? 0 : 1;
}
