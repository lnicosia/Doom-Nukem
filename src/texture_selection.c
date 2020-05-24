/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:10:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/20 13:14:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int	texture_tab2(t_env *env)
{
	int	i;

	i = -1;
	while (++i < MAX_SKYBOX)
	{
		if (draw_button(env, env->editor.skyboxes[i],
		env->editor.skyboxes[i].str))
			return (-1);
	}
	return (0);
}

int	texture_tab(t_env *env, int nb_slots)
{
	int	mod;
	int	test;
	int	i;

	test = nb_slots;
	if (nb_slots > 50)
		mod = 15;
	if (nb_slots > 25)
		mod = 10;
	else
		mod = 5;
	while (test % mod != 0)
		test++;
	draw_rectangle(env, new_rectangle(0, 0xFF333333, 1, 5),
	env->editor.texture_selection_pos, env->editor.texture_selection_size);
	i = -1;
	while (++i < MAX_WALL_TEXTURE)
	{
		if (draw_button(env, env->editor.textures[i],
		env->editor.textures[i].str))
			return (-1);
	}
	return (texture_tab2(env));
}
