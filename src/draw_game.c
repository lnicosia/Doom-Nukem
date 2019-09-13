/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:50:14 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/13 17:07:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	draw_game(t_env *env)
{
	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
	env->test_time = SDL_GetTicks();
	if (draw_walls2(env))
		return (crash("Failed to draw walls\n", env));
	if (env->options.wall_color)
	{
		draw_objects(env);
		draw_enemies(env);
	}
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
	if (env->options.zbuffer)
		update_screen_zbuffer(env);
	else
		update_screen(env);
	view(env);
	return (0);
}
