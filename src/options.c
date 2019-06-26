/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:30 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/26 18:26:25 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		init_screen_size(t_env *env, int i)
{
	env->screen_w[0] = 2560;
	env->screen_h[0] = 1600;
	env->screen_w[1] = 1920;
	env->screen_h[1] = 1080;
	env->screen_w[2] = 1600;
	env->screen_h[2] = 900;
	if (!(env->res = (char**)malloc(sizeof(char*) * 3)))
		return (0);
	if (!(env->res[0] = (char*)malloc(sizeof(char) * 11)))
		return (0);
	if (!(env->res[1] = (char*)malloc(sizeof(char) * 11)))
		return (0);
	if (!(env->res[2] = (char*)malloc(sizeof(char) * 10)))
		return (0);
	env->res[0] = "2560 x 1600";
	env->res[1] = "1920 x 1080";
	env->res[2] = "1600 x 900";
	env->i = 1;
	env->w = env->screen_w[i];
	env->h = env->screen_h[i];
	return (0);
}

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
	if (env->sdl.event.key.keysym.sym == SDLK_o)
	{
		env->option = env->option ? 0 : 1;
		if (env->option)
			SDL_SetRelativeMouseMode(0);
		else
			SDL_SetRelativeMouseMode(1);
	}
}

void	screen_options(t_env *env)
{
	add_image(env, 30, 910, 350);
	add_image(env, 31, 1120, 350);
	print_text(new_point(350 , env->w / 2 - 300), new_printable_text("Screen size :", env->sdl.fonts.alice30, 0x960018FF, 30), env);
	print_text(new_point(350 , env->w / 2), new_printable_text(env->res[env->i], env->sdl.fonts.alice30, 0x960018FF, 30), env);

}

void	sound_options(t_env *env)
{
	char	*sound;

	ft_printf("sound: %d\n", env->sound.g_music);
	sound = ft_itoa(env->sound.g_music);
	add_image(env, 30, 910, 450);
	add_image(env, 31, 1120, 450);
		print_text(new_point(450 , env->w / 2 - 300), new_printable_text("Sound :", env->sdl.fonts.alice30, 0x960018FF, 30), env);
	print_text(new_point(450 , env->w / 2 + 50), new_printable_text(sound, env->sdl.fonts.alice30, 0x960018FF, 30), env);

}

int		open_options(t_env *env)
{
	SDL_SetRelativeMouseMode(0);
	clear_image(env);
	add_image(env, 29, 0, 0);	
	print_text(new_point(200 , env->w / 2 - 150), new_printable_text("OPTIONS", env->sdl.fonts.alice70, 0x960018FF, 70), env);
	screen_options(env);
	sound_options(env);
	update_screen(env);
	return (0);
}
