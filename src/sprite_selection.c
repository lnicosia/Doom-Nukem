/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:34:34 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/04 14:33:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	sprite_selection(t_env *env, int nb_slots)
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
				new_point(180, 490),
				new_point((64 * mod) + 10, (64 * (test / mod)) + 10));
	while (i < MAX_OBJECTS)
	{
		draw_button(env, env->editor.sprite_selection[i],
		env->editor.sprite_selection[i].str);
		i++;
	}
}
