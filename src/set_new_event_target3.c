/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_event_target3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:31:28 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 15:55:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

void		set_buttons_state(t_env *env)
{
	if (env->editor.event_panel.target_panel.floor_type)
		set_floor_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.ceiling_type)
		set_ceiling_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.wall_type)
		set_wall_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.wall_sprite_type)
		set_wall_sprite_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.weapon_type)
		set_weapon_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.enemy_type)
		set_enemy_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.object_type)
		set_object_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.player_type)
		set_player_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.vertex_type)
		set_vertex_panel_buttons_state(env);
	if (env->editor.event_panel.target_panel.sector_other_type)
		set_sector_other_panel_buttons_state(env);
}

void		set_target_panel_buttons_state(t_env *env)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		env->editor.event_panel.target_panel.targets[i].state = UP;
		env->editor.event_panel.target_panel.targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.event_panel.event.target)
		set_buttons_state(env);
}

int			set_wall_sprite2(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int wall)
{
	int	sector;
	int	sprite;

	sector = env->editor.selected_sector;
	sprite = env->selected_wall_sprite_sprite;
	if (target_panel->targets[3].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].scale[sprite].x;
		panel->event.target_index = SECTOR_WALL_SPRITES_SCALE_X;
	}
	else if (target_panel->targets[4].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].scale[sprite].y;
		panel->event.target_index = SECTOR_WALL_SPRITES_SCALE_Y;
	}
	panel->event.update_param.sector = sector;
	panel->event.check_param.sector = sector;
	panel->event.update_param.wall = wall;
	panel->event.check_param.wall = wall;
	panel->event.update_param.sprite = sprite;
	panel->event.check_param.sprite = sprite;
	set_target_panel_buttons_state(env);
	return (0);
}

int			set_wall_sprite(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int wall)
{
	int	sector;
	int	sprite;

	sector = env->editor.selected_sector;
	sprite = env->selected_wall_sprite_sprite;
	if (target_panel->targets[0].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].sprite[sprite];
		panel->event.target_index = SECTOR_WALL_SPRITES_SPRITE;
		panel->event.type = INT;
	}
	else if (target_panel->targets[1].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].pos[sprite].x;
		panel->event.target_index = SECTOR_WALL_SPRITES_POS_X;
	}
	else if (target_panel->targets[2].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].pos[sprite].y;
		panel->event.target_index = SECTOR_WALL_SPRITES_POS_Y;
	}
	return (set_wall_sprite2(env, panel, target_panel, wall));
}

int			select_wall_sprite_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel)
{
	if (env->selected_wall_sprite_wall != -1)
		return (set_wall_sprite(env, panel, target_panel,
		env->selected_wall_sprite_wall));
	else if (env->selected_floor != -1)
		return (set_floor_sprite(env, panel, target_panel,
		env->selected_floor));
	else if (env->selected_ceiling != -1)
		return (set_ceiling_sprite(env, panel, target_panel,
		env->selected_ceiling));
		return (0);
}
