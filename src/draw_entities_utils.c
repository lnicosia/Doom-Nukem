/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_entities_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:50:05 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 16:15:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "enemies.h"

void	get_rendered_objects(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_objects)
	{
		j = 0;
		while (j < env->nb_rendered_sectors)
		{
			if (env->objects[i].sector == env->rendered_sectors[j])
			{
				env->rendered_objects[env->nb_rendered_objects] = i;
				env->nb_rendered_objects++;
			}
			j++;
		}
		i++;
	}
}

void	get_rendered_enemies(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_enemies)
	{
		j = 0;
		while (j < env->nb_rendered_sectors)
		{
			if (env->enemies[i].sector == env->rendered_sectors[j])
			{
				env->rendered_enemies[env->nb_rendered_enemies] = i;
				env->nb_rendered_enemies++;
			}
			j++;
		}
		i++;
	}
}
