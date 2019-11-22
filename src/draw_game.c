/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:50:14 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/22 14:19:08 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	draw_render(t_camera *camera, t_env *env)
{
	if (draw_walls(camera, env))
		return (crash("Failed to draw walls\n", env));
	draw_objects(*camera, env);
	draw_projectiles(*camera, env);
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
	if (((env->inputs.left_click && !env->shot.on_going && !env->weapon_change.on_going) || env->shot.on_going) && env->player.health > 0)
		weapon_animation(env, env->player.curr_weapon);
	else if (env->player.health > 0)
		draw_weapon(env, env->weapons[env->player.curr_weapon].first_sprite);
	if (env->weapon_change.on_going && !env->shot.on_going)
		weapon_change(env);
	draw_crosshair(env);
	if (env->options.show_fps)
		fps(env);
	if (env->options.test)
		print_debug(env);
	game_time(env);
	animations(env);
	if (env->player.health > 0)
	{
		draw_hud(env);
		interactions(env);
		print_ammo(env);
	}
	else
		print_results(env);
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
	/*t_list *tmp;
	t_projectile *proj;
	tmp = env->projectiles;
	while (tmp)
	{
		proj = ((t_projectile*)tmp->content);
		if (proj->exists)
		{
			draw_line(new_point(proj->left, proj->top), new_point(proj->right, proj->top), *env, 0xFF00FF00);
			draw_line(new_point(proj->right, proj->top), new_point(proj->right, proj->bottom), *env, 0xFF00FF00);
			draw_line(new_point(proj->right, proj->bottom), new_point(proj->left, proj->bottom), *env, 0xFF00FF00);
			draw_line(new_point(proj->left, proj->bottom), new_point(proj->left, proj->top), *env, 0xFF00FF00);
		}
		tmp = tmp->next;
	}*/}
	//if (env->options.show_minimap)
		minimap(env);
	if (env->confirmation_box.state)
		draw_confirmation_box(env->confirmation_box, env);
	if (env->options.zbuffer)
		update_screen_zbuffer(env);
	else
		update_screen(env);
	if (env->player.health > 0)
		view(env);
	env->first_frame = 1;
	return (0);
}
