/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:34:34 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 10:57:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

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
				new_rectangle(0x00000000, 0xFF333333, 1, 5),
				env->editor.wall_sprite_selection_pos,
				env->editor.wall_sprite_selection_size);
	while (i < MAX_OBJECTS)
	{
		apply_sprite(env->object_sprites[env->objects_main_sprites[i]],
		new_point(490 + 8 + (66 * (i / mod)),
		180 + (66 * (i % mod)) + 8),
		new_point(64, 64), env);
		i++;
	}
}
