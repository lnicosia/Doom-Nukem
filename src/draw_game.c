/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:50:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/11 15:03:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemies.h"
#include "draw.h"

int	draw_render(t_camera *camera, t_env *env)
{
	if (draw_walls(camera, env))
		return (-1);
	if (draw_objects(camera, env))
		return (-1);
	if (draw_projectiles(camera, env))
		return (-1);
	if (draw_explosions(camera, env))
		return (-1);
	if (draw_enemies(camera, env))
		return (-1);
	return (0);
}

int	create_bullet_holes(t_env *env)
{
	if (env->new_wall_bullet_hole && add_wall_hitscan_bullet_hole(
		&env->sectors[env->new_bullet_hole_sector], env->new_bullet_hole_wall,
		env))
		return (-1);
	if (env->new_floor_bullet_hole && add_floor_hitscan_bullet_hole(
		&env->sectors[env->new_bullet_hole_sector], env))
		return (-1);
	if (env->new_ceiling_bullet_hole && add_ceiling_hitscan_bullet_hole(
		&env->sectors[env->new_bullet_hole_sector], env))
		return (-1);
	env->new_wall_bullet_hole = 0;
	env->new_floor_bullet_hole = 0;
	env->new_ceiling_bullet_hole = 0;
	env->new_bullet_hole_sector = -1;
	env->new_bullet_hole_wall = -1;
	return (0);
}

int	draw_game2(t_env *env)
{
	if (is_player_alive(env))
		return (-1);
	if (env->player.hit)
		damage_anim(env);
	if (env->hovered_wall_sprite_sprite != -1
		&& env->hovered_wall_sprite_wall != -1
		&& env->hovered_wall_sprite_sector != -1)
	{
		if (print_press_text(env))
			return (-1);
	}
	if (env->confirmation_box.state)
	{
		if (draw_confirmation_box(&env->confirmation_box, env))
			return (-1);
	}
	if (env->dialog_box && env->dialog_box_str
		&& draw_dialog_box(&env->dialog_box_str, env))
		return (-1);
	if (update_screen(env))
		return (-1);
	if (!env->confirmation_box.state)
		view(env);
	return (0);
}

int	draw_game(t_env *env)
{
	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
	if (draw_render(&env->player.camera, env))
		return (-1);
	if (create_bullet_holes(env))
		return (-1);
	env->shooting = 0;
	env->test_time = SDL_GetTicks();
	if(draw_weapons(env))
		return (-1);
	if (env->options.show_fps)
	{
		if (fps(env))
			return (-1);
	}
	draw_crosshair(env);
	game_time(env);
	animations(env);
	game_minimap(env);
	return (draw_game2(env));
}
