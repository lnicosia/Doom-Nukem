/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites_state.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:31:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/20 12:53:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_walls_sprites_state(t_env *env)
{
	t_sector	sector;
	int			i;
	int			j;
	double		diff;

	i = 0;
	while (i < env->nb_sectors)
	{
		sector = env->sectors[i];
		j = 0;
		while (j < sector.nb_vertices)
		{
			diff = env->time.milli_s - sector.sprite_time;
			if ((int)diff % 340 > 170)
			{
				env->sectors[i].sprite_time = 0;
				env->sectors[i].sprites[j].sprite = env->sprites[sector.sprites[j].sprite].rest_sprite;
				//env->sectors[i].sprites[j].sprite = 3;
			}
			else
			{
				env->sectors[i].sprite_time = 0;
				env->sectors[i].sprites[j].sprite = env->sprites[sector.sprites[j].sprite].rest_sprite;
				//env->sectors[i].sprites[j].sprite = 1;
			}
			j++;
		}
		i++;
	}
}

void	update_sprites_state(t_env *env)
{
	update_walls_sprites_state(env);
}
