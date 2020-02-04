/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:02:08 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/04 10:19:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


void	print_events_tab(t_env *env)
{
	(void)env;
	if (env->selected_wall_sprite_wall == -1
		&& (env->selected_floor != -1 || env->editor.selected_sector != -1))
	{
		print_sector_events_tab(env);
	}
	else if (env->selected_wall_sprite_wall != -1)
	{
		print_wall_sprite_events_tab(env);
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
	{
		print_global_events_tab(env);
	}
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
		draw_button(env, env->editor.next_sprite);
		draw_button(env, env->editor.previous_sprite);
		draw_button(env, env->editor.sprite_background);
		draw_button(env, env->editor.current_sprite_selection);
	}
}

void	print_sector_tab(t_env *env)
{
	/*
	if (env->editor.selected_vertex != -1)
		print_vertex_general_tab(env);*/
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
	/*if (env->editor.selected_vertex != -1)
		print_vertex_general_tab(env);*/
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
	print_text(new_point(450, 180), new_printable_text("vertex ",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(450, 280), new_printable_text(ft_sitoa(env->editor.selected_vertex),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(490, 50), new_printable_text("Coordonates:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 80), new_printable_text("X:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 230), new_printable_text(ft_sitoa(env->vertices[env->editor.selected_vertex].x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(580, 80), new_printable_text("Y:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(580, 230), new_printable_text(ft_sitoa(env->vertices[env->editor.selected_vertex].y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	return (0);
}

int	draw_editor_tabs(t_env *env)
{
	if ((env->editor.in_game && (env->selected_ceiling_sprite == -1
	&& env->selected_floor_sprite == -1 && env->selected_wall_sprite_sprite == -1)
	&& (env->selected_object != - 1 || env->editor.selected_wall != - 1 ||
	env->selected_floor != -1 || env->selected_enemy != -1 || env->selected_ceiling != -1 ))
	|| (!env->editor.in_game && (env->editor.selected_sector != -1 || env->editor.selected_player != -1
	|| env->selected_object != -1 || env->selected_enemy != -1)))
		draw_button(env, env->editor.general_tab);
	if ((!env->editor.in_game && (env->editor.selected_player != -1 || env->selected_enemy != -1
	|| env->selected_object != -1)) || (env->editor.in_game
	&& (env->selected_object != - 1 || env->editor.selected_wall != - 1 ||
	env->editor.selected_wall_sprite != -1 || env->selected_floor_sprite != -1 ||
	env->selected_floor != -1 || env->selected_enemy != -1
	|| env->selected_ceiling != -1 || env->selected_wall_sprite_sprite != -1 
	|| env->selected_ceiling != -1)))
		draw_button(env, env->editor.sector_tab);
	if (is_events_tab_visible(env))
		draw_button(env, env->editor.events_tab);
	if (env->editor.in_game && env->editor.tab &&
	(env->selected_ceiling_sprite != -1 || env->selected_floor_sprite != -1
	|| env->selected_wall_sprite_sprite != -1))
		draw_button(env, env->editor.sprite_tab);
	new_tabs_position(env);
	if (env->editor.sector_tab.state == DOWN)
		print_sector_tab(env);
	else if (env->editor.sprite_tab.state == DOWN)
		print_sprite_tab(env);
	else if (env->editor.general_tab.state == DOWN)
		print_general_tab(env);
	else if (is_events_tab_visible(env))
	{
		if (env->editor.events_tab.state == DOWN)
			print_events_tab(env);
	}
	if (env->editor.draw_selection_tab)
		selection_tab(env, MAX_WALL_TEXTURE + MAX_SKYBOX);
	return (0);
}
