/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_bullet_hole.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:31:01 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/29 18:38:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		shift_floor_bullet_hole(t_sector *sector, t_projectile *projectile)
{
	int	i;
	int	j;

	i = 0;
	(void)projectile;
	while (i < sector->nb_floor_sprites)
	{
		if (sector->floor_sprites.sprite[i] == 3)
		{
			j = i;
			while (sector->floor_sprites.sprite[j] != 3
				&& j < sector->nb_floor_sprites)
				j++;
			if (j < sector->nb_floor_sprites)
			{
			}
		}
		i++;
	}
	return (0);
}
