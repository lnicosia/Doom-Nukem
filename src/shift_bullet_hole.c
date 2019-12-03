/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_bullet_hole.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:31:01 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/02 11:16:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		shift_floor_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < sector->nb_floor_sprites)
	{
		if (sector->floor_sprites.sprite[i] == 3)
		{
			j = i + 1;
			while (sector->floor_sprites.sprite[j] != 3
				&& j < sector->nb_floor_sprites)
				j++;
			if (j < sector->nb_floor_sprites)
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
	while (i < sector->nb_ceiling_sprites)
	{
		if (sector->ceiling_sprites.sprite[i] == 3)
		{
			j = i + 1;
			while (sector->ceiling_sprites.sprite[j] != 3
				&& j < sector->nb_ceiling_sprites)
				j++;
			if (j < sector->nb_ceiling_sprites)
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
	while (j < sector->nb_sprites[i])
	{
		if (sector->sprites[i].sprite[j] == 3)
		{
			k = j + 1;
			while (sector->sprites[i].sprite[k] != 3
				&& k < sector->nb_sprites[i])
				k++;
			if (k < sector->nb_sprites[i])
			{
				sector->sprites[i].pos[j] =
				sector->sprites[i].pos[k];
				sector->sprites[i].scale[j] =
				sector->sprites[i].scale[k];
			}
			else
			{
				sector->sprites[i].pos[j] = 
				get_wall_bullet_hole_pos(sector, projectile, i, env);
				sector->sprites[i].pos[j].x -=
				sector->sprites[i].scale[j].x / 2;
				sector->sprites[i].pos[j].y -=
				sector->sprites[i].scale[j].y / 2;
			}
		}
		j++;
	}
	return (0);
}
