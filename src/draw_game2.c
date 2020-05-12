/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:58:00 by marvin            #+#    #+#             */
/*   Updated: 2020/05/11 14:58:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemies.h"
#include "draw.h"

int     is_player_alive(t_env *env)
{
    if (env->player.health > 0)
	{
		if (draw_hud(env))
			return (-1);
		if (print_ammo(env))
			return (-1);
	}
	else
	{
		if (print_results(env))
			return (-1);
	}
    return (0);
}

int     draw_weapons(t_env *env)
{
    if (((env->inputs.left_click && !env->shot.on_going
		&& !env->weapon_change.on_going) || env->shot.on_going)
		&& !env->confirmation_box.state)
	{
		if (weapon_animation(env, env->player.curr_weapon))
			return (-1);
	}
	else if (env->player.health > 0)
		draw_weapon(env, env->weapons[env->player.curr_weapon].first_sprite);
	if (env->weapon_change.on_going && !env->shot.on_going)
		weapon_change(env);
    return (0);
}