/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:30:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/07 20:51:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		draw_target_panel(t_env *env)
{
	t_point	text_size;

	TTF_SizeText(env->sdl.fonts.lato_black30, "Choose your event's target",
	&text_size.x, &text_size.y);
	print_text(new_point(
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 17,
	env->editor.event_panel.pos.x + 100 +
	(env->editor.event_panel.size.x - 100) / 2 - text_size.x / 2),
	new_printable_text("Choose your event's target", env->sdl.fonts.lato_black30,
	0x333333FF, 0), env);
	draw_button(env, env->editor.event_panel.target_panel.sector, "Sector");
	draw_button(env, env->editor.event_panel.target_panel.wall, "Wall");
	draw_button(env, env->editor.event_panel.target_panel.wall_sprite, "Wall"
	" sprite");
	draw_button(env, env->editor.event_panel.target_panel.weapon, "Weapon");
	draw_button(env, env->editor.event_panel.target_panel.enemy, "Enemy");
	draw_button(env, env->editor.event_panel.target_panel.object, "Object");
	draw_button(env, env->editor.event_panel.target_panel.player, "Player");
	draw_button(env, env->editor.event_panel.target_panel.other, "Other");
	return (0);
}
