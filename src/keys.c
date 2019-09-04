/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/04 17:50:01 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		keys(t_env *env)
{
	if (!env->jump.on_going && env->inputs.space)
		update_floor(env);
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
		Mix_PlayChannel(-1, env->sound.footstep, 0);
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
			|| env->crouch.on_going || env->inputs.ctrl || env->gravity.on_going)
		move_player(env);
	if (env->inputs.plus && !env->inputs.shift
			&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	if (env->inputs.minus && !env->inputs.shift
			&& env->options.minimap_scale / 1.2 > 5)
		env->options.minimap_scale /= 1.2;
	if (env->inputs.up && !env->inputs.shift && !env->editor.tab)
	{
		env->sectors[env->player.sector].floor_slope += 0.01;
		update_sector_slope(env, &env->sectors[env->player.sector]);
		if (env->sectors[env->player.sector].floor_max
				> env->sectors[env->player.sector].ceiling_min)
		{
			env->sectors[env->player.sector].floor_slope -= 0.01;
			update_sector_slope(env, &env->sectors[env->player.sector]);
		}
	}
	/*
	 * *	selection of textures on walls
	 */

	if (env->editor.tab && env->editor.in_game && (env->inputs.up || env->inputs.down)
			&& env->editor.selected_wall != -1)
	{
		if (env->inputs.down
				&& env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] > 0)
			env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]--;
		else if (env->inputs.up
				&& env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] < MAX_TEXTURE - 1)
			env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]++;
	}
	
	/*
	 * *	selection of textures on ceiling and floor
	 */

	if (env->editor.in_game && env->inputs.right_click)
	{
		env->editor.selected_wall = -1;
		env->editor.selected_sector = -1;
		env->selected_wall1 = -1;
		env->selected_wall2 = -1;
		env->selected_ceiling = -1;
		env->selected_floor = -1;
	}
	if (env->editor.tab && env->editor.in_game && (env->inputs.up || env->inputs.down)
			&& env->editor.selected_wall != -1)
	{
		if (env->inputs.down
				&& env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] > 0)
			env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]--;
		else if (env->inputs.up
				&& env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] < MAX_TEXTURE - 1)
			env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]++;
	}


	if (env->inputs.down && !env->inputs.shift && !env->editor.tab)
	{
		env->sectors[env->player.sector].floor_slope -= 0.01;
		update_sector_slope(env, &env->sectors[env->player.sector]);
	}
	if (env->inputs.up && env->inputs.shift)
	{
		env->sectors[env->player.sector].ceiling_slope += 0.01;
		update_sector_slope(env, &env->sectors[env->player.sector]);
	}
	if (env->inputs.down && env->inputs.shift)
	{
		env->sectors[env->player.sector].ceiling_slope -= 0.01;
		update_sector_slope(env, &env->sectors[env->player.sector]);
		if (env->sectors[env->player.sector].floor_max
				> env->sectors[env->player.sector].ceiling_min)
		{
			env->sectors[env->player.sector].ceiling_slope += 0.01;
			update_sector_slope(env, &env->sectors[env->player.sector]);
		}
	}
	if (env->inputs.right_click && !env->option)
	{
		if (env->weapons[env->player.curr_weapon].ammo < env->weapons[env->player.curr_weapon].max_ammo)
			env->weapons[env->player.curr_weapon].ammo++;
	}
}
