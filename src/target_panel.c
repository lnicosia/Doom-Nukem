/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:30:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 15:45:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"
#include "events.h"

int		draw_first_phase_selection(t_env *env, t_target_panel *panel)
{
	if (draw_button(env, panel->sector, "Sector"))
		return (-1);
	if (draw_button(env, panel->wall, "Wall"))
		return (-1);
	if (draw_button(env, panel->wall_sprite, "Wall sprite"))
		return (-1);
	if (draw_button(env, panel->weapon, "Weapon"))
		return (-1);
	if (draw_button(env, panel->enemy, "Enemy"))
		return (-1);
	if (draw_button(env, panel->object, "Object"))
		return (-1);
	if (draw_button(env, panel->player, "Player"))
		return (-1);
	if (draw_button(env, panel->vertex, "Vertex"))
		return (-1);
	if (draw_button(env, panel->other, "Other"))
		return (-1);
	return (0);
}

int		draw_third_phase_selection(t_env *env, t_target_panel *panel)
{
	if (draw_button(env, panel->previous, NULL))
		return (-1);
	if (panel->wall_type)
	{
		if (draw_wall_panel(env, panel))
			return (-1);
	}
	else if (panel->wall_sprite_type)
	{
		if (draw_wall_sprite_panel(env, panel))
			return (-1);
	}
	else if (panel->object_type)
	{
		if (draw_object_panel(env, panel))
			return (-1);
	}
	else if (panel->weapon_type)
	{
		if (draw_weapon_panel(env, panel))
			return (-1);
	}
	else if (panel->enemy_type)
	{
		if (draw_enemy_panel(env, panel))
			return (-1);
	}
	else if (panel->player_type)
	{
		if (draw_player_panel(env, panel))
			return (-1);
	}
	else if (panel->vertex_type)
	{
		if (draw_vertex_panel(env, panel))
			return (-1);
	}
	else if (panel->floor_type)
	{
		if (draw_floor_panel(env, panel))
			return (-1);
	}
	else if (panel->ceiling_type)
	{
		if (draw_ceiling_panel(env, panel))
			return (-1);
	}
	else if (panel->sector_other_type)
	{
		if (draw_sector_other_panel(env, panel))
			return (-1);
	}
	else if (panel->other_type)
	{
		if (draw_other_panel(env, panel))
			return (-1);
	}
	return (0);
}

int		draw_second_phase_selection(t_env *env, t_target_panel *panel)
{
	if (draw_button(env, panel->previous, NULL))
		return (-1);
	if (draw_button(env, panel->floor, "Floor"))
		return (-1);
	if (draw_button(env, panel->ceiling, "Ceiling"))
		return (-1);
	if (draw_button(env, panel->sector_other, "Other"))
		return (-1);
	return (0);
}

int		draw_target_panel2(t_env *env)
{
	int		phase;

	phase = get_target_selection_phase(&env->editor.event_panel.target_panel);
	if (phase == 0)
	{
		if (draw_first_phase_selection(env,
			&env->editor.event_panel.target_panel))
			return (-1);
	}
	else if (phase == 1)
	{
		if (draw_second_phase_selection(env,
			&env->editor.event_panel.target_panel))
			return (-1);
	}
	else if (phase == 2)
	{
		if (draw_third_phase_selection(env,
			&env->editor.event_panel.target_panel))
			return (-1);
	}
	return (0);
}

int		draw_target_panel(t_env *env)
{
	t_point			text_size1;
	t_point			text_size2;
	t_event_panel	panel;

	panel = env->editor.event_panel;
	if (TTF_SizeText(env->sdl.fonts.lato_black30, "Choose your event's target",
	&text_size1.x, &text_size1.y))
		return (-1);
	if (print_text(new_point(panel.pos.y + panel.top_size + 17,
	panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size1.x / 2),
	new_printable_text("Choose your event's target",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env))
		return (-1);
	if (panel.event.target)
	{
		env->print_target_data[panel.event.target_index](env, &panel.event,
		new_point(panel.pos.y + panel.top_size + 17 + text_size1.y,
		panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size1.x / 2),
		20);
		if (TTF_SizeText(env->sdl.fonts.lato20, env->snprintf,
		&text_size2.x, &text_size2.y))
			return (-1);
		if (print_text(new_point(panel.pos.y + panel.top_size + 17
		+ text_size1.y, panel.pos.x + 100 + panel.content_panel_size.x / 2
		- text_size2.x / 2), new_printable_text(env->snprintf,
		env->sdl.fonts.lato20, 0x333333FF, 0), env))
			return (-1);
	}
	return (draw_target_panel2(env));
}
