/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_checkers3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:10:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:10:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_texture_input_box(void *penv)
{
	int		texture;
	t_env	*env;

	env = (t_env*)penv;
	texture = ft_atoi(env->input_box.str);
	if (texture < -MAX_SKYBOX || texture >= MAX_WALL_TEXTURE)
		return (1);
	return (0);
}

int		check_sprite_input_box(void *penv)
{
	int		sprite;
	t_env	*env;

	env = (t_env*)penv;
	sprite = ft_atoi(env->input_box.str);
	if (sprite < 0 || sprite >= MAX_OBJECT_SPRITES)
		return (1);
	return (0);
}

int		check_sprite_scale_input_box(void *penv)
{
	double	scale;
	t_env	*env;

	env = (t_env*)penv;
	scale = ft_atof(env->input_box.str);
	if ((scale < 0.1 && scale > -0.1) || scale > 100 || scale < -100)
		return (1);
	return (0);
}
