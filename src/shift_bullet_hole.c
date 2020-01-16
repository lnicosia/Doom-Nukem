/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_bullet_hole.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:31:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/15 16:05:55 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		shift_floor_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < sector->floor_sprites.nb_sprites)
	{
		if (sector->floor_sprites.sprite[i] == 3)
		{
			j = i + 1;
			while (j < sector->floor_sprites.nb_sprites &&
			sector->floor_sprites.sprite[j] != 3)
				j++;
			if (j < sector->floor_sprites.nb_sprites)
			{
				sector->floor_sprites.pos[i] = sector->floor_sprites.pos[j];
				sector->floor_sprites.scale[i] = sector->floor_sprites.scale[j];
			}
			else
			{
				sector->floor_sprites.pos[i] = 
				get_floor_bullet_hole_pos(sector, projectile, env);
				sector->floor_sprites.pos[i].x -=
				sector->floor_sprites.scale[i].x / 2;
				sector->floor_sprites.pos[i].y -=
				sector->floor_sprites.scale[i].y / 2;
			}
		}
		i++;
	}
	return (0);
}

int		shift_ceiling_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < sector->ceiling_sprites.nb_sprites)
	{
		if (sector->ceiling_sprites.sprite[i] == 3)
		{
			j = i + 1;
			while (j < sector->ceiling_sprites.nb_sprites &&
			sector->ceiling_sprites.sprite[j] != 3)
				j++;
			if (j < sector->ceiling_sprites.nb_sprites)
			{
				sector->ceiling_sprites.pos[i] = sector->ceiling_sprites.pos[j];
				sector->ceiling_sprites.scale[i] = sector->ceiling_sprites.scale[j];
			}
			else
			{
				sector->ceiling_sprites.pos[i] = 
				get_ceiling_bullet_hole_pos(sector, projectile, env);
				sector->ceiling_sprites.pos[i].x -=
				sector->ceiling_sprites.scale[i].x / 2;
				sector->ceiling_sprites.pos[i].y -=
				sector->ceiling_sprites.scale[i].y / 2;
			}
		}
		i++;
	}
	return (0);
}

int		shift_wall_bullet_hole(t_sector *sector, t_projectile *projectile,
int i, t_env *env)
{
	int	j;
	int	k;

	j = 0;
	while (j < sector->wall_sprites[i].nb_sprites)
	{
		if (sector->wall_sprites[i].sprite[j] == 3)
		{
			k = j + 1;
			while (k < sector->wall_sprites[i].nb_sprites &&
				sector->wall_sprites[i].sprite[k] != 3)
				k++;
			if (k < sector->wall_sprites[i].nb_sprites)
			{
				sector->wall_sprites[i].pos[j] =
				sector->wall_sprites[i].pos[k];
				sector->wall_sprites[i].scale[j] =
				sector->wall_sprites[i].scale[k];
			}
			else
			{
				sector->wall_sprites[i].pos[j] = 
				get_wall_bullet_hole_pos(sector, projectile, i, env);
				sector->wall_sprites[i].pos[j].x -=
				sector->wall_sprites[i].scale[j].x / 2;
				sector->wall_sprites[i].pos[j].y -=
				sector->wall_sprites[i].scale[j].y / 2;
			}
		}
		j++;
	}
	return (0);
}
