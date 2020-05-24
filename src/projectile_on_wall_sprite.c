/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_on_wall_sprite.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:05:05 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/06 11:20:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int		projectile_on_wall_sprite(t_v2 pos, t_sector *sector, int wall,
		t_env *env)
{
	int		i;

	i = 0;
	while (i < sector->wall_sprites[wall].nb_sprites)
	{
		if (pos.x >= sector->wall_sprites[wall].pos[i].x
			&& pos.x <= sector->wall_sprites[wall].pos[i].x
			+ sector->wall_sprites[wall].scale[i].x
			&& pos.y >= sector->wall_sprites[wall].pos[i].y
			&& pos.y <= sector->wall_sprites[wall].pos[i].y
			+ sector->wall_sprites[wall].scale[i].y)
		{
			if (sector->wall_sprites[wall].nb_shoot_events[i] > 0
				&& start_event(&sector->wall_sprites[wall].shoot_events[i],
					&sector->wall_sprites[wall].nb_shoot_events[i], env))
				return (-1);
		}
		i++;
	}
	return (0);
}
