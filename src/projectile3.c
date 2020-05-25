/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:43:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:43:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	projectile_hits_nothing(t_v3 move, t_projectile *projectile,
t_list **tmp, t_env *env)
{
	projectile->pos.x += move.x;
	projectile->pos.y += move.y;
	projectile->pos.z += move.z;
	projectile->sector =
	get_sector_no_z_origin(env, projectile->pos, projectile->sector);
	if (projectile->sector != -1)
	{
		projectile->brightness = env->sectors[projectile->sector].brightness;
		projectile->intensity = env->sectors[projectile->sector].intensity;
		projectile->light_color = env->sectors[projectile->sector].light_color;
	}
	*tmp = (*tmp)->next;
}

int		projectile_hits_floor(t_projectile *projectile, t_env *env)
{
	if (create_explosion(env, new_explosion_data(projectile->pos, 7,
		projectile->damage,
		env->object_sprites[projectile->sprite].death_counterpart), 1))
		return (-1);
	env->nb_explosions++;
	if (env->sectors[projectile->sector].floor_sprites.nb_sprites 
		+ ft_lstlen(env->sectors[projectile->sector].floor_bullet_holes)
		< env->options.max_floor_sprites)
	{
		if (add_floor_projectile_bullet_hole(
			&env->sectors[projectile->sector], projectile, env))
			return (-1);
	}
	else if (shift_floor_bullet_hole(&env->sectors[projectile->sector],
		projectile, env))
		return (-1);
	return (0);
}

int		projectile_hits_ceiling(t_projectile *projectile, t_env *env)
{
	if (create_explosion(env, new_explosion_data(projectile->pos, 7,
		projectile->damage,
		env->object_sprites[projectile->sprite].death_counterpart), 1))
		return (-1);
	env->nb_explosions++;
	if (env->sectors[projectile->sector].ceiling_sprites.nb_sprites
		+ ft_lstlen(env->sectors[projectile->sector].ceiling_bullet_holes)
		< env->options.max_floor_sprites)
	{
		if (add_ceiling_projectile_bullet_hole(
			&env->sectors[projectile->sector], projectile, env))
			return (-1);
	}
	else if (shift_ceiling_bullet_hole(&env->sectors[projectile->sector],
		projectile, env))
		return (-1);
	return (0);
}

int		projectile_hits_wall(int collision, t_projectile *projectile,
t_env *env)
{
	if (create_explosion(env, new_explosion_data(projectile->pos, 7,
		projectile->damage,
		env->object_sprites[projectile->sprite].death_counterpart), 1))
		return (-1);
	env->nb_explosions++;
	if (env->sectors[projectile->sector].wall_sprites[collision].
		nb_sprites < env->options.max_wall_sprites)
	{
		if (add_wall_projectile_bullet_hole(
			&env->sectors[projectile->sector], projectile, collision, env))
			return (-1);
	}
	else if (shift_wall_bullet_hole(&env->sectors[projectile->sector],
		projectile, collision, env))
		return (-1);
	return (0);
}
