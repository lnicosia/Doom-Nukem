/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:30:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 12:08:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_first_phase_selection(t_env *env)
{
	t_target_panel	panel;

	panel = env->editor.event_panel.target_panel;
	draw_button(env, panel.sector, "Sector");
	draw_button(env, panel.wall, "Wall");
	draw_button(env, panel.wall_sprite, "Wall sprite");
	draw_button(env, panel.weapon, "Weapon");
	draw_button(env, panel.enemy, "Enemy");
	draw_button(env, panel.object, "Object");
	draw_button(env, panel.player, "Player");
	draw_button(env, panel.other, "Other");
}

void	draw_third_phase_selection(t_env *env)
{
	t_target_panel	panel;

	panel = env->editor.event_panel.target_panel;
	draw_button(env, panel.previous, NULL);
	/*if (panel.wall_type)
	else if (panel.wall_sprite_type)
	else if (panel.object_type)
	else if (panel.weapon_type)
	else if (panel.enemy_type)
	else if (panel.player_type)
	else if (panel.other_type)
	else if (panel.floor_type)
	else if (panel.ceiling_type)
	else if (panel.sector_other_type)*/
}

void	draw_second_phase_selection(t_env *env)
{
	t_target_panel	panel;

	panel = env->editor.event_panel.target_panel;
	draw_button(env, panel.previous, NULL);
	draw_button(env, panel.floor, "Floor");
	draw_button(env, panel.ceiling, "Ceiling");
	draw_button(env, panel.sector_other, "Other");
}

int		draw_target_panel(t_env *env)
{
	t_point			text_size;
	t_event_panel	panel;
	int				phase;

	panel = env->editor.event_panel;
	TTF_SizeText(env->sdl.fonts.lato_black30, "Choose your event's target",
	&text_size.x, &text_size.y);
	print_text(new_point(panel.pos.y + panel.top_size + 17,
	panel.pos.x + 100 + (panel.size.x - 100) / 2 - text_size.x / 2),
	new_printable_text("Choose your event's target",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env);
	phase = get_target_selection_phase(env);
	if (phase == 0)
		draw_first_phase_selection(env);
	else if (phase == 1)
		draw_second_phase_selection(env);
	else if (phase == 2)
		draw_third_phase_selection(env);
	return (0);
}
