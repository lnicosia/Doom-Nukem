/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:23:02 by gaerhard          #+#    #+#             */
/*   Updated: 2020/01/15 14:34:52 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	projectile_coord(t_v3 pos, t_projectile *projectile, double angle_z, double height)
{
	projectile->pos.x = 2.5 * cos(projectile->angle) + pos.x;
	projectile->pos.y = 2.5 * sin(projectile->angle) + pos.y;
	projectile->pos.z = 2.5 * -angle_z + pos.z + height;
//	projectile->pos.z = height;
	projectile->dest.x = 100000000 * cos(projectile->angle)
	+ projectile->pos.x;
	projectile->dest.y = 100000000 * sin(projectile->angle)
	+ projectile->pos.y;
	projectile->dest.z = 100000000 * -angle_z + projectile->pos.z;
}

int		create_projectile(t_env *env, t_projectile_data data, t_projectile_stats stats, double angle_z)
{
	t_list	*new;

	if (!(new = ft_lstnew(&env->projectile, sizeof(t_projectile))))
		return (ft_printf("Error when creating new projectile\n"));
	ft_lstpushback(&env->projectiles, new);
	((t_projectile*)new->content)->sprite = data.sprite;
	((t_projectile*)new->content)->speed = stats.speed;
	((t_projectile*)new->content)->angle = data.angle;
	projectile_coord(data.pos, ((t_projectile*)new->content), angle_z, stats.height);
	((t_projectile*)new->content)->scale = data.scale;
	((t_projectile*)new->content)->damage = stats.damage;
	((t_projectile*)new->content)->size_2d = stats.size_2d;
	((t_projectile*)new->content)->exists = 1;
	((t_projectile*)new->content)->sector = get_sector_no_z(env, ((t_projectile*)new->content)->pos);
	((t_projectile*)new->content)->angle = data.angle * CONVERT_DEGREES;
	return (0);
}

int		projectiles_movement(t_env *env)
{
	int				nb;
	t_v3			move;
	t_list			*tmp;
	t_projectile	*projectile;
	int				collision;

	if (env->projectiles)
	{
		tmp = env->projectiles;
		while (tmp)
		{
			projectile = (t_projectile*)tmp->content;
			move = sprite_movement(env, projectile->speed, projectile->pos, projectile->dest);
			nb = enemy_collision(env, projectile->pos,
					new_v3(projectile->pos.x + move.x, projectile->pos.y + move.y, projectile->pos.z + move.z),
					projectile->size_2d);
			if (nb >= 0)
			{
				env->enemies[nb].health -= projectile->damage;
				env->enemies[nb].hit = 1;
				create_explosion(env, new_explosion_data(projectile->pos, 7, projectile->damage, env->object_sprites[projectile->sprite].death_counterpart), 1);
				tmp = ft_lstdelnode(&env->projectiles, tmp);
				continue ;
			}
			nb = projectile_object_collision(env, projectile->pos,
				new_v3(projectile->pos.x + move.x, projectile->pos.y + move.y, projectile->pos.z + move.z),
				projectile->size_2d); 
			if (nb >= 0 && env->objects[nb].solid)
			{
				create_explosion(env, new_explosion_data(projectile->pos, 7, projectile->damage, env->object_sprites[projectile->sprite].death_counterpart), 1);
				tmp = ft_lstdelnode(&env->projectiles, tmp);
				continue ;
			}
			if (projectile_player_collision(env, projectile->pos,
						new_v3(projectile->pos.x + move.x, projectile->pos.y + move.y, projectile->pos.z + move.z),
						projectile->size_2d))
			{
				env->player.hit = 1;
				env->player.health -= ft_clamp(projectile->damage - env->player.armor, 0, projectile->damage);
				env->player.armor -= ft_clamp(projectile->damage, 0, env->player.armor);
				tmp = ft_lstdelnode(&env->projectiles, tmp);
				continue ;
			}
			collision = collision_projectiles(env, move,
					new_movement(projectile->sector, projectile->size_2d,
						0, projectile->pos));
			if (collision == -1)
			{
				projectile->pos.x += move.x;
				projectile->pos.y += move.y;
				projectile->pos.z += move.z;
				projectile->sector = get_sector_no_z_origin(env, projectile->pos, projectile->sector);
				if (projectile->sector != -1)
				{
					projectile->brightness
					= env->sectors[projectile->sector].brightness;
					projectile->intensity
					= env->sectors[projectile->sector].intensity;
					projectile->light_color
					= env->sectors[projectile->sector].light_color;
				}
				tmp = tmp->next;
			}
			else
			{
				/*projectile->pos.x += move.x;
				projectile->pos.y += move.y;
				projectile->pos.z += move.z;*/
				if (collision == -2 && env->sectors[projectile->sector].ceiling_texture >= 0)
				{
					create_explosion(env, new_explosion_data(projectile->pos, 7, projectile->damage, env->object_sprites[projectile->sprite].death_counterpart), 1);
					if (env->sectors[projectile->sector].ceiling_sprites.nb_sprites
						< env->options.max_floor_sprites)
					{
						
						if (add_ceiling_bullet_hole(
							&env->sectors[projectile->sector], projectile,
							env))
							return (-1);
					}
					else if (shift_ceiling_bullet_hole(
						&env->sectors[projectile->sector], projectile,
						env))
						return (-1);
				}
				else if (collision == -3 && env->sectors[projectile->sector].floor_texture >= 0)
				{
					create_explosion(env, new_explosion_data(projectile->pos, 7, projectile->damage, env->object_sprites[projectile->sprite].death_counterpart), 1);
					if (env->sectors[projectile->sector].floor_sprites.nb_sprites
						< env->options.max_floor_sprites)
					{
						if (add_floor_bullet_hole(
							&env->sectors[projectile->sector], projectile,
							env))
							return (-1);
					}
					else if (shift_floor_bullet_hole(
						&env->sectors[projectile->sector], projectile,
						env))
						return (-1);
				}
				else if (collision >= 0 && env->sectors[projectile->sector].textures[collision] >= 0)
				{
					create_explosion(env, new_explosion_data(projectile->pos, 7, projectile->damage, env->object_sprites[projectile->sprite].death_counterpart), 1);
					if (env->sectors[projectile->sector]
						.wall_sprites[collision].nb_sprites
						< env->options.max_wall_sprites)
					{
						if (add_wall_bullet_hole(
							&env->sectors[projectile->sector],
							projectile, collision, env))
							return (-1);
					}
					else if (shift_wall_bullet_hole(
						&env->sectors[projectile->sector], projectile,
						collision, env))
						return (-1);
				}
				tmp = ft_lstdelnode(&env->projectiles, tmp);
			}
		}
	}
	return (0);
}
