/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_wall_bullet_hole.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:31:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:47:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	shift_wall_current_bullet_hole(t_point index, t_sector *sector,
t_projectile *projectile, t_env *env)
{
	int	k;

	k = index.y + 1;
	while (k < sector->wall_sprites[index.x].nb_sprites &&
		sector->wall_sprites[index.x].sprite[k] != 3)
		k++;
	if (k < sector->wall_sprites[index.x].nb_sprites)
	{
		sector->wall_sprites[index.x].pos[index.y] =
		sector->wall_sprites[index.x].pos[k];
		sector->wall_sprites[index.x].scale[index.y] =
		sector->wall_sprites[index.x].scale[k];
	}
	else
	{
		sector->wall_sprites[index.x].pos[index.y] =
		get_wall_bullet_hole_pos(sector, projectile, index.x, env);
		sector->wall_sprites[index.x].pos[index.y].x -=
		sector->wall_sprites[index.x].scale[index.y].x / 2;
		sector->wall_sprites[index.x].pos[index.y].y -=
		sector->wall_sprites[index.x].scale[index.y].y / 2;
	}
}

int		shift_wall_bullet_hole(t_sector *sector, t_projectile *projectile,
int i, t_env *env)
{
	int	j;

	j = 0;
	while (j < sector->wall_sprites[i].nb_sprites)
	{
		if (sector->wall_sprites[i].sprite[j] == 3)
		{
			shift_wall_current_bullet_hole(new_point(i, j), sector, projectile,
			env);
		}
		j++;
	}
	return (0);
}
