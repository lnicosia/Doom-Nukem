/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:30:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 15:59:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_first_phase_selection(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->sector, "Sector");
	draw_button(env, panel->wall, "Wall");
	draw_button(env, panel->wall_sprite, "Wall sprite");
	draw_button(env, panel->weapon, "Weapon");
	draw_button(env, panel->enemy, "Enemy");
	draw_button(env, panel->object, "Object");
	draw_button(env, panel->player, "Player");
	draw_button(env, panel->vertex, "Vertex");
}

void	draw_third_phase_selection(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->previous, NULL);
	if (panel->wall_type)
		draw_wall_panel(env, panel);
	else if (panel->wall_sprite_type)
		draw_wall_sprite_panel(env, panel);
	else if (panel->object_type)
		draw_object_panel(env, panel);
	else if (panel->weapon_type)
		draw_weapon_panel(env, panel);
	else if (panel->enemy_type)
		draw_enemy_panel(env, panel);
	else if (panel->player_type)
		draw_player_panel(env, panel);
	else if (panel->vertex_type)
		draw_vertex_panel(env, panel);
	else if (panel->floor_type)
		draw_floor_panel(env, panel);
	else if (panel->ceiling_type)
		draw_ceiling_panel(env, panel);
	else if (panel->sector_other_type)
		draw_sector_other_panel(env, panel);
}

void	draw_second_phase_selection(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->previous, NULL);
	draw_button(env, panel->floor, "Floor");
	draw_button(env, panel->ceiling, "Ceiling");
	draw_button(env, panel->sector_other, "Other");
}

int		draw_target_panel(t_env *env)
{
	t_point			text_size1;
	t_point			text_size2;
	t_event_panel	panel;
	int				phase;

	panel = env->editor.event_panel;
	TTF_SizeText(env->sdl.fonts.lato_black30, "Choose your event's target",
	&text_size1.x, &text_size1.y);
	print_text(new_point(panel.pos.y + panel.top_size + 17,
	panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size1.x / 2),
	new_printable_text("Choose your event's target",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env);
	if (panel.event.target)
	{
		env->print_target_data[panel.event.target_index](env, &panel.event,
		new_point(panel.pos.y + panel.top_size + 17 + text_size1.y,
		panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size1.x / 2),
		20);
		TTF_SizeText(env->sdl.fonts.lato20, env->snprintf,
		&text_size2.x, &text_size2.y);
		print_text(new_point(panel.pos.y + panel.top_size + 17 + text_size1.y,
		panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size2.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato20, 0x333333FF, 0), env);
	}
	phase = get_target_selection_phase(&env->editor.event_panel.target_panel);
	if (phase == 0)
		draw_first_phase_selection(env, &env->editor.event_panel.target_panel);
	else if (phase == 1)
		draw_second_phase_selection(env, &env->editor.event_panel.target_panel);
	else if (phase == 2)
		draw_third_phase_selection(env, &env->editor.event_panel.target_panel);
	return (0);
}
