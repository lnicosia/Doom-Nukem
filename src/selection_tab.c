/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:10:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/04 14:37:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	texture_tab(t_env *env, int nb_slots)
{
	int mod;
	int	test;
	int	i;

	i = 0;
	test = nb_slots;
	if (nb_slots > 25)
		mod = 10;
	else
		mod = 5;
	while (test % mod != 0)
		test++;	
	draw_rectangle(env,
				new_rectangle(0x00000000, 0xFF888888, 1, 5),
				new_point(300, 150),
				new_point((64 * mod) + 10, (64 * (test / mod)) + 10 + 20));
	while (i < MAX_WALL_TEXTURE)
	{
		draw_button(env, env->editor.textures[i], env->editor.textures[i].str);
		i++;
	}
	i = 0;
	while (i < MAX_SKYBOX)
	{
		draw_button(env, env->editor.skyboxes[i], env->editor.skyboxes[i].str);
		i++;
	}
}