/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites_state.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:31:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:40:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_floor_and_ceiling_sprites_state(t_sector *sector, t_env *env)
{
	int		j;

	j = 0;
	while (j < sector->floor_sprites.nb_sprites)
	{
		sector->floor_sprites.sprite[j] =
		env->object_sprites[sector->floor_sprites.sprite[j]].rest_sprite;
		j++;
	}
	j = 0;
	while (j < sector->ceiling_sprites.nb_sprites)
	{
		sector->ceiling_sprites.sprite[j] =
		env->object_sprites[sector->ceiling_sprites.sprite[j]].rest_sprite;
		j++;
	}
}

void	update_wall_sprites_state(int j, t_sector *sector, t_env *env)
{
	int			k;

	k = -1;
	while (++k < sector->wall_sprites[j].nb_sprites)
	{
		if (sector->wall_sprites[j].sprite[k] == -1)
			continue;
		sector->wall_sprites[j].sprite[k] =
		env->object_sprites[sector->wall_sprites[j].sprite[k]].rest_sprite;
	}
}

void	update_walls_sprites_state(t_env *env)
{
	int			i;
	int			j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		update_floor_and_ceiling_sprites_state(&env->sectors[i], env);
		while (j < env->sectors[i].nb_vertices)
		{
			update_wall_sprites_state(j, &env->sectors[i], env);
			j++;
		}
		i++;
	}
}

void	update_sprites_state(t_env *env)
{
	double		diff;

	diff = env->time.milli_s - env->sprite_time;
	if (diff > 200)
	{
		update_walls_sprites_state(env);
		env->sprite_time = env->time.milli_s;
	}
}
