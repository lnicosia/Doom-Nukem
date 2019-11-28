/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:29:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/26 14:32:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		apply_texture(int texture, t_sector *sector, t_env *env)
{
		int	i;

		(void)env;
		i = 0;
		while (i < sector->nb_vertices)
		{
				sector->textures[i] = texture;
				if (set_sector_wall_map_array(sector,
					env->wall_textures[sector->textures[i]], i, env))
					return (-1);
				if (env->editor.in_game
					&& set_camera_map_array(&env->player.camera,
					sector->num, i, env))
					return (-1);
				i++;
		}
		sector->floor_texture = texture;
		if (set_sector_floor_map_array(sector,
			env->wall_textures[sector->floor_texture], env))
			return (-1);
		sector->ceiling_texture = texture;
		if (set_sector_ceiling_map_array(sector,
			env->wall_textures[sector->ceiling_texture], env))
			return (-1);
		return (0);
}
