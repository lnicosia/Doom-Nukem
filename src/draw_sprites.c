/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:04:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/20 18:10:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

void		draw_object(t_object object, t_env *env, t_render *render)
{
	t_render_object	orender;

	(void)render;
	get_translated_object_pos(&orender, object, env);
	get_rotated_object_pos(&orender, env);
}

void		draw_sprites(t_env *env, t_render *render)
{
	int	i;

	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector == render->sector && !env->objects[i].drawn)
			draw_object(env->objects[i], env, render);
		i++;
	}
}
