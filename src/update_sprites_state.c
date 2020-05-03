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

void	update_wall_sprites_state(int i, int j, t_sector *sector, t_env *env)
{
	int			k;
	double		diff;

	diff = env->time.milli_s - sector->sprite_time;
	k = -1;
	while (++k < sector->wall_sprites[j].nb_sprites)
	{
		if (sector->wall_sprites[j].sprite[k] == -1)
			continue;
		if (diff > 200)
		{
			env->sectors[i].sprite_time = env->time.milli_s;
			env->sectors[i].wall_sprites[j].sprite[k] =
			env->object_sprites[env->sectors[i].
			wall_sprites[j].sprite[k]].rest_sprite;
		}
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
		while (j < env->sectors[i].nb_vertices)
		{
			update_wall_sprites_state(i, j, &env->sectors[i], env);
			j++;
		}
		i++;
	}
}

void	update_sprites_state(t_env *env)
{
	update_walls_sprites_state(env);
}
