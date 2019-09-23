/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/23 10:37:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		keys(t_env *env)
{
	double	time;
	int		i;

	i = 0;
	time = SDL_GetTicks();
	if (!env->time.tick)
		env->time.tick = SDL_GetTicks();
	if (!env->jump.on_going && env->inputs.space)
		update_floor(env);
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
		Mix_PlayChannel(-1, env->sound.footstep, 0);
	if ((((env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
			|| env->crouch.on_going || env->inputs.ctrl || env->gravity.on_going)
			&& !env->editor.in_game)

			&& (((env->selected_enemy == -1 && env->editor.tab)
				|| (env->selected_enemy != -1 && !env->editor.tab))
				|| (env->selected_enemy == -1 && !env->editor.tab)))
	
			|| (!env->inputs.ctrl && env->editor.in_game))

		move_player(env);
	if (env->inputs.plus && !env->inputs.shift
			&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	if (env->inputs.minus && !env->inputs.shift
			&& env->options.minimap_scale / 1.2 > 5)
		env->options.minimap_scale /= 1.2;
	if (env->editor.in_game && env->inputs.right_click)
	{
		env->editor.selected_wall = -1;
		env->editor.selected_sector = -1;
		env->selected_wall1 = -1;
		env->selected_wall2 = -1;
		env->selected_ceiling = -1;
		env->selected_floor = -1;
		env->selected_enemy = -1;
	}

	/*
	 * *	selection of textures on walls
	 */
	if (env->editor.tab && env->editor.in_game
			&& env->editor.selected_wall != -1)
	{
		if (time - env->time.tick > 200)
		{
			env->time.tick = time;
			if (env->inputs.down
					&& env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] > -1)
				env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]--;
			else if (env->inputs.up
					&& env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] < MAX_TEXTURE - 1)
				env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]++;
		}
		if (env->inputs.comma)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y--;
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x--;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y--;
			else
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x--;
		}
		if (env->inputs.period)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y++;
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x++;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y++;
			else
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x++;
		}
		if (env->inputs.equals)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y--;
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x--;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y--;
			else
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x--;
		}
		if (env->inputs.minus1)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y++;
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x++;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y++;
			else
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x++;
		}
	}

	/*
	 * *	selection of textures on ceiling and floor
	 */

	if (env->editor.in_game && env->selected_ceiling != -1)
	{
		if (time - env->time.tick > 200)
		{
			env->time.tick = time;
			if (env->inputs.down && env->editor.tab
					&& env->sectors[env->selected_ceiling].ceiling_texture > -1)
				env->sectors[env->selected_ceiling].ceiling_texture--;
			else if (env->inputs.up && env->editor.tab
					&& env->sectors[env->selected_ceiling].ceiling_texture < MAX_TEXTURE - 1)
				env->sectors[env->selected_ceiling].ceiling_texture++;
			if (env->sectors[env->selected_ceiling].ceiling_texture == -1)
			{
				env->sectors[env->selected_ceiling].skybox = 1;
				env->sectors[env->selected_ceiling].ceiling_texture = 38;
			}
			else if (env->sectors[env->selected_ceiling].ceiling_texture != 38)
				env->sectors[env->selected_ceiling].skybox = 0;

		}
		if (env->inputs.plus
				&& env->sectors[env->selected_ceiling].ceiling > env->sectors[env->selected_ceiling].floor + 1)
			env->sectors[env->selected_ceiling].ceiling += 0.05;
		if (env->inputs.minus
				&& env->sectors[env->selected_ceiling].ceiling)
			env->sectors[env->selected_ceiling].ceiling -= 0.05;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		if (env->inputs.comma)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_ceiling].ceiling_align.y--;
				env->sectors[env->selected_ceiling].ceiling_align.x--;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling_align.y--;
			else
				env->sectors[env->selected_ceiling].ceiling_align.x--;
		}
		if (env->inputs.period)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_ceiling].ceiling_align.y++;
				env->sectors[env->selected_ceiling].ceiling_align.x++;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling_align.y++;
			else
				env->sectors[env->selected_ceiling].ceiling_align.x++;
		}
		if (env->inputs.equals)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_ceiling].ceiling_scale.y--;
				env->sectors[env->selected_ceiling].ceiling_scale.x--;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling_scale.y--;
			else
				env->sectors[env->selected_ceiling].ceiling_scale.x--;
		}
		if (env->inputs.minus1)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_ceiling].ceiling_scale.y++;
				env->sectors[env->selected_ceiling].ceiling_scale.x++;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling_scale.y++;
			else
				env->sectors[env->selected_ceiling].ceiling_scale.x++;
		}

	}
	if (env->editor.in_game && env->selected_floor != -1)
	{
		if (time - env->time.tick > 200 && env->editor.tab)
		{
			env->time.tick = time;
			if (env->inputs.down
					&& env->sectors[env->selected_floor].floor_texture > 0)
				env->sectors[env->selected_floor].floor_texture--;
			if (env->inputs.up
					&& env->sectors[env->selected_floor].floor_texture < MAX_TEXTURE - 1)
				env->sectors[env->selected_floor].floor_texture++;
		}
		if (env->inputs.plus
				&& env->sectors[env->selected_floor].floor < env->sectors[env->selected_floor].ceiling - 1)
			env->sectors[env->selected_floor].floor += 0.05;
		else if (env->inputs.minus)
			env->sectors[env->selected_floor].floor -= 0.05;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		if (env->inputs.comma)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_floor].floor_align.y--;
				env->sectors[env->selected_floor].floor_align.x--;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_floor].floor_align.y--;
			else
				env->sectors[env->selected_floor].floor_align.x--;
		}
		if (env->inputs.period)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_floor].floor_align.y++;
				env->sectors[env->selected_floor].floor_align.x++;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_floor].floor_align.y++;
			else
				env->sectors[env->selected_floor].floor_align.x++;
		}
		if (env->inputs.equals)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_floor].floor_scale.y--;
				env->sectors[env->selected_floor].floor_scale.x--;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_floor].floor_scale.y--;
			else
				env->sectors[env->selected_floor].floor_scale.x--;
		}
		if (env->inputs.minus1)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_floor].floor_scale.y++;
				env->sectors[env->selected_floor].floor_scale.x++;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_floor].floor_scale.y++;
			else
				env->sectors[env->selected_floor].floor_scale.x++;
		}
	}

	/*
	 * *	selection of slopes on floor and ceiling
	 */
	if (env->inputs.down && !env->inputs.shift && !env->editor.tab
			&& env->editor.in_game && env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope -= 0.01;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	if (env->inputs.up && !env->inputs.shift && !env->editor.tab
			&& env->editor.in_game && env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope += 0.01;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	if (env->selected_ceiling != -1 && env->sectors[env->selected_ceiling].ceiling_slope <= 0.02
			&& env->sectors[env->selected_ceiling].ceiling_slope >= -0.02 && (!env->inputs.up && !env->inputs.down))
		env->sectors[env->selected_ceiling].ceiling_slope = 0;

	if (env->inputs.down && !env->inputs.shift && !env->editor.tab
			&& env->editor.in_game && env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope -= 0.01;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_enemies_z(env);
		update_enemies_z(env);
		update_objects_z(env);
	}
	if (env->inputs.up && !env->inputs.shift && !env->editor.tab
			&& env->editor.in_game && env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope += 0.01;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_enemies_z(env);
		update_objects_z(env);
	}
	if (env->selected_floor != -1 && env->sectors[env->selected_floor].floor_slope <= 0.02
			&& env->sectors[env->selected_floor].floor_slope >= -0.02 && (!env->inputs.up && !env->inputs.down))
		env->sectors[env->selected_floor].floor_slope = 0;
	if (env->selected_floor != -1 && env->editor.in_game && env->inputs.ctrl)
	{
		if (!env->time.tick3)
			env->time.tick3 = SDL_GetTicks();
		if (env->inputs.left && time - env->time.tick3 > 250)
		{
			env->sectors[env->selected_floor] = rotate_vertices(env, 1, env->selected_floor);
			env->time.tick3 = time;
		}
		else if (env->inputs.right && time - env->time.tick3 > 250)
		{
			env->sectors[env->selected_floor] = rotate_vertices(env, -1, env->selected_floor);
			env->time.tick3 = time;
		}
		env->sectors[env->selected_floor].normal = get_sector_normal(env->sectors[env->selected_floor], env);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		clear_portals(env);
		while (i < env->nb_sectors)
		{
			create_portals(env, env->sectors[i]);
			i++;
		}
	}
	if (env->selected_ceiling != -1 && env->editor.in_game && env->inputs.ctrl)
	{
		if (!env->time.tick3)
			env->time.tick3 = SDL_GetTicks();
		if (env->inputs.left && time - env->time.tick3 > 250)
		{
			env->sectors[env->selected_ceiling] = rotate_vertices(env, 1, env->selected_ceiling);
			env->time.tick3 = time;
		}
		else if (env->inputs.right && time - env->time.tick3 > 250)
		{
			env->sectors[env->selected_ceiling] = rotate_vertices(env, -1, env->selected_ceiling);
			env->time.tick3 = time;
		}
		env->sectors[env->selected_ceiling].normal = get_sector_normal(env->sectors[env->selected_ceiling], env);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		update_player_z(env);
		clear_portals(env);
		while (i < env->nb_sectors)
		{
			create_portals(env, env->sectors[i]);
			i++;
		}
	}

	/*
	 * *	select the stats of an enemy
	 */

	if (env->editor.tab && env->selected_enemy != -1 && env->editor.in_game)
	{
		time = SDL_GetTicks();
		if (!env->time.tick2)
			env->time.tick2 = SDL_GetTicks();
		if (env->inputs.backward && env->selected_stat < 3 && time - env->time.tick2 > 250)
		{
			env->time.tick2 = time;
			env->selected_stat++;
		}
		else if (env->inputs.forward && env->selected_stat > 0 && time - env->time.tick2 > 250)
		{
			env->time.tick2 = time;
			env->selected_stat--;
		}
		if (env->selected_enemy != -1)
			selected_information_on_enemy(env);
	}
	if (env->inputs.right_click && !env->option)
	{
		//ft_printf("player pos %f, %f\n", env->player.pos.x, env->player.pos.y);
		if (env->weapons[env->player.curr_weapon].ammo < env->weapons[env->player.curr_weapon].max_ammo)
			env->weapons[env->player.curr_weapon].ammo++;
	}
}
