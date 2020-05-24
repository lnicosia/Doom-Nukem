/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_explosions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:24:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:29:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		draw_current_explosion(t_camera *camera, t_explosion *explosion,
t_list **tmp, t_env *env)
{
	int		sprite_index;

	if (explosion->rotated_pos.z > 1)
	{
		sprite_index = explosion_animation(env, explosion,
		env->object_sprites[explosion->sprite].nb_death_sprites);
		if (sprite_index >= 0)
		{
			if (draw_explosion(camera, explosion, env, sprite_index))
				return (-1);
			*tmp = (*tmp)->next;
		}
		else
			*tmp = ft_lstdelnode(&env->explosions, *tmp);
	}
	else
		*tmp = (*tmp)->next;
	return (0);
}

int		draw_explosions(t_camera *camera, t_env *env)
{
	t_list			*tmp;
	t_explosion		*explosion;

	get_explosion_relative_pos(camera, env);
	tmp = env->explosions;
	while (tmp)
	{
		explosion = (t_explosion*)tmp->content;
		if (draw_current_explosion(camera, explosion, &tmp, env))
			return (-1);
	}
	return (0);
}
