/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:30 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 12:22:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		keyup(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_c)
		env->options.contouring = env->options.contouring ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_r)
		ft_printf("will reload one day\n");
	if (env->sdl.event.key.keysym.sym == SDLK_m)
	{
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
		env->options.mipmapping = env->options.mipmapping ? 0 : 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_f)
		env->options.show_fps = env->options.show_fps ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_x)
		env->options.wall_lover = env->options.wall_lover ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_j)
		env->options.color_clipping = env->options.color_clipping ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_g)
		env->options.wall_color = env->options.wall_color ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_i)
		env->options.clipping = env->options.clipping ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		env->next_dialog = 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_n)
		env->drawing = env->drawing ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_p)
		env->options.p = env->options.p ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_e
		&& env->hovered_wall_sprite_sprite != -1
		&& env->hovered_wall_sprite_wall != -1
		&& env->hovered_wall_sprite_sector != -1
		&& env->sectors[env->hovered_wall_sprite_sector]
		.wall_sprites[env->hovered_wall_sprite_wall]
		.nb_press_events[env->hovered_wall_sprite_sprite]
		&& env->sectors[env->hovered_wall_sprite_sector]
		.wall_sprites[env->hovered_wall_sprite_wall]
		.press_events[env->hovered_wall_sprite_sprite])
	{
		if (start_event(&env->sectors[env->hovered_wall_sprite_sector]
		.wall_sprites[env->hovered_wall_sprite_wall]
		.press_events[env->hovered_wall_sprite_sprite],
		&env->sectors[env->hovered_wall_sprite_sector]
		.wall_sprites[env->hovered_wall_sprite_wall]
		.nb_press_events[env->hovered_wall_sprite_sprite], env))
			return (-1);
		if (env->sectors[env->hovered_wall_sprite_sector]
		.wall_sprites[env->hovered_wall_sprite_wall]
		.nb_press_events[env->hovered_wall_sprite_sprite] == 0)
		{
			env->hovered_wall_sprite_wall = -1;
			env->hovered_wall_sprite_sector = -1;
			env->hovered_wall_sprite_sprite = -1;
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_o)
		env->option = env->option ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_TAB)
		env->options.zbuffer = env->options.zbuffer ? 0 : 1;
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keyup(&env->confirmation_box, env))
			return (-1);
	}
	return (0);
}
