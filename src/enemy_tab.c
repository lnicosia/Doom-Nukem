/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:03:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/04 14:33:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	enemy_tab(t_env *env, int nb_slots)
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
				new_point(50, 290),
				new_point((64 * mod) + 10, (64 * (test / mod)) + 10));
	while (i < MAX_ENEMIES)
	{
		draw_button(env, env->editor.enemy_tab[i], env->editor.enemy_tab[i].str);
		i++;
	}
}
