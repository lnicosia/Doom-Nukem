/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites_state.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:31:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/29 12:33:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_walls_sprites_state(t_env *env)
{
	t_sector	sector;
	int			i;
	int			j;
	int			k;
	double		diff;

	i = 0;
	while (i < env->nb_sectors)
	{
		sector = env->sectors[i];
		j = 0;
		while (j < sector.nb_vertices)
		{
			diff = env->time.milli_s - sector.sprite_time;
			k = -1;
			while (++k < sector.nb_sprites[j])
			{
				if (sector.sprites[j].sprite[k] == -1)
					continue;
				if (diff > 200)
				{
					env->sectors[i].sprite_time = env->time.milli_s;
					env->sectors[i].sprites[j].sprite[k] = env->sprites[env->sectors[i].sprites[j].sprite[k]].rest_sprite;
				}
			}
			j++;
		}
		i++;
	}
}

void	update_sprites_state(t_env *env)
{
	(void)env;
	update_walls_sprites_state(env);
}
