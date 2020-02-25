/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_wall_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:27:36 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 13:26:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		delete_wall_sprite(void *param)
{
	t_env	*env;
	int		wall;
	int		sector;

	env = (t_env*)param;
	sector = env->editor.selected_sector;
	wall = env->selected_wall_sprite_wall;
	//env->sectors[sector].wall_sprites[wall].
	return (0);
}
