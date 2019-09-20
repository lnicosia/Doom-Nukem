/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:50:14 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/20 08:32:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	draw_render(t_camera *camera, t_env *env)
{
	if (draw_walls(camera, env))
		return (crash("Failed to draw walls\n", env));
	draw_objects(*camera, env);
	draw_enemies(*camera, env);
	draw_players(*camera, env);
	return (0);
}

int	draw_game(t_env *env)
{
	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
	env->test_time = SDL_GetTicks();
	if (draw_render(&env->player.camera, env))
		return (crash("Failed to draw render\n", env));
	if ((env->inputs.left_click && !env->shot.on_going && !env->weapon_change.on_going) || env->shot.on_going)
		weapon_animation(env, env->player.curr_weapon);
	else
		draw_weapon(env, env->weapons[env->player.curr_weapon].first_sprite);
	if (env->weapon_change.on_going && !env->shot.on_going)
		weapon_change(env);
	draw_crosshair(env);
	print_ammo(env);
	if (env->options.show_fps)
		fps(env);
	if (env->options.test)
		print_debug(env);
	if (env->options.show_minimap)
		minimap(env);
	game_time(env);
	animations(env);
	draw_hud(env);
	if (env->player.hit)
		damage_anim(env);
	int i = 0;
	if (env->options.test)
	{
		while (i < env->nb_enemies)
		{
			if (env->enemies[i].exists)
			{
				draw_line(new_point(env->enemies[i].left, env->enemies[i].top), new_point(env->enemies[i].right, env->enemies[i].top), *env, 0xFF00FF00);
				draw_line(new_point(env->enemies[i].right, env->enemies[i].top), new_point(env->enemies[i].right, env->enemies[i].bottom), *env, 0xFF00FF00);
				draw_line(new_point(env->enemies[i].right, env->enemies[i].bottom), new_point(env->enemies[i].left, env->enemies[i].bottom), *env, 0xFF00FF00);
				draw_line(new_point(env->enemies[i].left, env->enemies[i].bottom), new_point(env->enemies[i].left, env->enemies[i].top), *env, 0xFF00FF00);
			}
			i++;
		}
	}
	if (env->options.zbuffer)
		update_screen_zbuffer(env);
	else
		update_screen(env);
	view(env);
	return (0);
}
