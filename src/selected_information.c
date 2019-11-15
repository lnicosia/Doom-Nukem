/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selected_information.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:41:35 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/15 17:03:13 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	selected_information_on_enemy(t_env *env)
{
	double	time;

	time = SDL_GetTicks();
	if (env->selected_stat == 0 && time - env->time.tick2 > 300)
	{
		env->time.tick2 = time;
		if (env->inputs.left && env->enemies[env->selected_enemy].health > 5)
			env->enemies[env->selected_enemy].health -= 5;
		if (env->inputs.right && env->enemies[env->selected_enemy].health < 100)
			env->enemies[env->selected_enemy].health += 5;
	}
	else if (env->selected_stat == 1 && time - env->time.tick2 > 300)
	{
		env->time.tick2 = time;
		if (env->inputs.left && env->enemies[env->selected_enemy].speed > 0)
			env->enemies[env->selected_enemy].speed -= 5;
		if (env->inputs.right && env->enemies[env->selected_enemy].speed < 100)
			env->enemies[env->selected_enemy].speed += 5;
	}
	else if (env->selected_stat == 2 && time - env->time.tick2 > 300)
	{
		env->time.tick2 = time;
		if (env->inputs.left && env->enemies[env->selected_enemy].damage > 5)
			env->enemies[env->selected_enemy].damage -= 5;
		if (env->inputs.right && env->enemies[env->selected_enemy].damage < 100)
			env->enemies[env->selected_enemy].damage += 5;
	}
	else if (env->selected_stat == 3 && time - env->time.tick2 > 300)
	{
		env->time.tick2 = time;
		if (env->inputs.left && env->enemies[env->selected_enemy].sprite == 2)
		{
			env->enemies[env->selected_enemy].sprite--;
			env->enemies[env->selected_enemy].pos.z = get_floor_at_pos(env->sectors[env->enemies[env->selected_enemy].sector],
			new_v3(env->enemies[env->selected_enemy].pos.x, env->enemies[env->selected_enemy].pos.y, 0), env) + 5;
		}
		if (env->inputs.right && env->enemies[env->selected_enemy].sprite == 1)
		{
			env->enemies[env->selected_enemy].sprite++;
			env->enemies[env->selected_enemy].pos.z = get_floor_at_pos(env->sectors[env->enemies[env->selected_enemy].sector],
			new_v3(env->enemies[env->selected_enemy].pos.x, env->enemies[env->selected_enemy].pos.y, 0), env);
		}
	}
}

void	selected_information_in_sector(t_env *env)
{
	double	time;
	int		texture;

	time = SDL_GetTicks();
	if ((env->inputs.left || env->inputs.right) && env->selected_stat == 0 && time - env->time.tick2 > 250)
	{
		env->time.tick2 = time;
		if (env->inputs.left)
		{
			if (env->inputs.shift)
				env->sectors[env->editor.selected_sector].floor -= 10;
			else
				env->sectors[env->editor.selected_sector].floor -= 2;
		}
		if (env->inputs.right)
		{
			if (env->inputs.shift)
				env->sectors[env->editor.selected_sector].floor += 10;
			else
				env->sectors[env->editor.selected_sector].floor += 2;
		}
	}
	if ((env->inputs.left || env->inputs.right) && env->selected_stat == 1 && time - env->time.tick2 > 250)
	{
		env->time.tick2 = time;
		if (env->inputs.left)
			env->sectors[env->editor.selected_sector].ceiling -= 2;
		if (env->inputs.right)
			env->sectors[env->editor.selected_sector].ceiling += 2;
	}
	if ((env->inputs.left || env->inputs.right) && env->selected_stat == 2 && time - env->time.tick2 > 250)
	{
		env->time.tick2 = time;
		texture = env->sectors[env->editor.selected_sector].floor_texture;
		if (env->inputs.left && texture > 0)
			apply_texture(texture - 1,
			&env->sectors[env->editor.selected_sector], env);
		if (env->inputs.right && texture < MAX_WALL_TEXTURE - 1)
			apply_texture(texture + 1,
			&env->sectors[env->editor.selected_sector], env);
	}
	if ((env->inputs.left || env->inputs.right) && env->selected_stat == 3 && time - env->time.tick2 > 250)
	{
		env->time.tick2 = time;
		if (env->inputs.left
				&& env->sectors[env->editor.selected_sector].brightness > -254)
			env->sectors[env->editor.selected_sector].brightness -= 2;
		if (env->inputs.right
				&& env->sectors[env->editor.selected_sector].brightness < 254)
			env->sectors[env->editor.selected_sector].brightness += 2;
	}
					
	update_sector_slope(env, &env->sectors[env->editor.selected_sector]);
}
