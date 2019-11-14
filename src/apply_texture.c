/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:29:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/14 09:31:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		apply_texture(int texture, t_sector *sector, t_env *env)
{
		int	i;

		(void)env;
		i = 0;
		while (i < sector->nb_vertices)
		{
				sector->textures[i] = texture;
				i++;
		}
		sector->floor_texture = texture;
		sector->ceiling_texture = texture;
}
