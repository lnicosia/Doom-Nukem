/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:02:08 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/21 15:27:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


void	print_events_tab(t_env *env)
{
	if (env->selected_enemy != -1)
		print_enemy_events_tab(env);
	else if (env->selected_object != -1)
		print_object_events_tab(env);
	else if (env->selected_wall_sprite_wall == -1
		&& (env->selected_floor != -1 || env->editor.selected_sector != -1))
		print_sector_events_tab(env);
	else if (env->selected_wall_sprite_wall != -1)
		print_wall_sprite_events_tab(env);
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->selected_enemy == -1 && env->selected_object == -1)
		print_global_events_tab(env);
	draw_button(env, env->editor.new_event, "New event");
}

void	print_sprite_tab(t_env *env)
{
	if (env->selected_wall_sprite_wall != -1)
		print_wall_sprite_tab(env);
	else if (env->selected_ceiling_sprite != -1)
		print_ceiling_sprite_tab(env);	
	else if (env->selected_floor_sprite != -1)
		print_floor_sprite_tab(env);
	if (env->selected_floor_sprite != -1 || env->selected_wall_sprite_sprite != -1
	|| env->selected_ceiling_sprite != -1)
	{
		draw_button(env, env->editor.next_sprite, env->editor.next_sprite.str);
		draw_button(env, env->editor.previous_sprite,
		env->editor.previous_sprite.str);
		draw_button(env, env->editor.sprite_background,
		env->editor.sprite_background.str);
		draw_button(env, env->editor.current_sprite_selection,
		env->editor.current_sprite_selection.str);
	}
}

void	print_sector_tab(t_env *env)
{
	if (env->selected_object != -1 || env->selected_object != -1)
		print_object_sector_tab(env);
	else if (env->selected_enemy != -1)
		print_enemy_sector_tab(env);
	else if (env->editor.selected_player != -1)
		print_player_sector_tab(env);
	else if (env->selected_ceiling != -1)
		print_ceiling_sector_tab(env);
	else if (env->selected_floor != -1)
		print_floor_sector_tab(env);
	else if (env->editor.selected_wall != -1
	&& env->editor.selected_sector != -1)
		print_wall_sector_tab(env);
	else if(env->selected_wall_sprite_sprite != -1)
		print_wall_sprite_sector_tab(env);
}

void	print_general_tab(t_env *env)
{
	if (env->selected_object != -1 || env->selected_object != -1)
		print_object_general_tab(env);
	else if (env->editor.selected_sector != -1 && !env->editor.in_game)
		print_sector_general_tab(env);
	else if (env->selected_ceiling != -1)
		print_ceiling_general_tab(env);
	else if (env->selected_floor != -1)
		print_floor_general_tab(env);
	else if (env->editor.selected_player != -1)
		print_player_general_tab(env);
	else if (env->editor.selected_wall != -1 && env->editor.selected_sector != -1)
		print_wall_general_tab(env);
	else if (env->selected_enemy != -1)
		print_enemy_general_tab(env);
}

int		print_vertex_informations(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "vertex %d", env->editor.selected_vertex);
	print_text(new_point(450, 180), new_printable_text(env->snprintf,
				env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_text(new_point(490, 50), new_printable_text("Coordinates:",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "X: %.*f",
	get_decimal_len(env->vertices[env->editor.selected_vertex].x),
	env->vertices[env->editor.selected_vertex].x);
	print_text(new_point(540, 80), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Y: %.*f",
	get_decimal_len(env->vertices[env->editor.selected_vertex].y),
	env->vertices[env->editor.selected_vertex].y);
	print_text(new_point(580, 80), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	return (0);
}

int	draw_editor_tabs(t_env *env)
{
	if ((env->editor.in_game && (env->selected_ceiling_sprite == -1
	&& env->selected_floor_sprite == -1
	&& env->selected_wall_sprite_sprite == -1)
	&& (env->selected_object != - 1 || env->editor.selected_wall != - 1 ||
	env->selected_floor != -1 || env->selected_enemy != -1
	|| env->selected_ceiling != -1 ))
	|| (!env->editor.in_game && (env->editor.selected_sector != -1
	|| env->editor.selected_player != -1
	|| env->selected_object != -1 || env->selected_enemy != -1)))
		draw_button(env, env->editor.general_tab, env->editor.general_tab.str);
	if ((!env->editor.in_game && (env->editor.selected_player != -1
		|| env->selected_enemy != -1
	|| env->selected_object != -1)) || (env->editor.in_game
	&& (env->selected_object != - 1 || env->editor.selected_wall != - 1 ||
	env->editor.selected_wall_sprite != -1 || env->selected_floor_sprite != -1
	|| env->selected_floor != -1 || env->selected_enemy != -1
	|| env->selected_ceiling != -1 || env->selected_wall_sprite_sprite != -1 )))
		draw_button(env, env->editor.sector_tab, env->editor.sector_tab.str);
	draw_button(env, env->editor.events_tab, env->editor.events_tab.str);
	if (env->editor.in_game && env->editor.tab &&
	(env->selected_ceiling_sprite != -1 || env->selected_floor_sprite != -1
	|| env->selected_wall_sprite_sprite != -1))
		draw_button(env, env->editor.sprite_tab, env->editor.sprite_tab.str);
	if (env->editor.sector_tab.state == DOWN)
		print_sector_tab(env);
	else if (env->editor.sprite_tab.state == DOWN)
		print_sprite_tab(env);
	else if (env->editor.general_tab.state == DOWN)
		print_general_tab(env);
	if (env->editor.events_tab.state == DOWN)
		print_events_tab(env);
	if (env->editor.draw_texture_tab)
		texture_tab(env, MAX_WALL_TEXTURE + MAX_SKYBOX);
	return (0);
}
