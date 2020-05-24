/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:54:45 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:21:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		click_on_grid_player(t_env *env)
{
	if (env->inputs.left_click
		&& !env->input_box.state
		&& !env->confirmation_box.state
		&& env->editor.event_panel_dragged == -1
		&& env->editor.start_vertex == -1
		&& env->editor.dragged_player == -1
		&& env->editor.dragged_enemy == -1
		&& env->editor.dragged_object == -1
		&& env->editor.dragged_vertex == -1
		&& !is_mouse_on_any_selection_tab(env)
		&& env->editor.dragged_start_player == -1)
		return (1);
	return (0);
}

void	draw_player_sprite(double scale, t_point pos, t_env *env)
{
	t_point		size;

	size = new_point(scale,
	scale / (env->object_sprites[CAMERA_SPRITE].size[0].x
	/ (double)env->object_sprites[CAMERA_SPRITE].size[0].y));
	pos = new_point(pos.y - size.y / 2, pos.x - size.x / 2);
	if (env->editor.selected_player == 1)
		apply_sprite_selected(env->object_sprites[CAMERA_SPRITE], pos, size,
		env);
	else
		apply_sprite(env->object_sprites[CAMERA_SPRITE], pos, size, env);
}

void	player_not_clicked(t_point *pos, double *scale, t_env *env)
{
	pos->x = (env->player.pos.x * env->editor.scale) + env->editor.center.x;
	pos->y = (env->player.pos.y * env->editor.scale) + env->editor.center.y;
	if (env->sdl.mx > pos->x - env->editor.scale
			&& env->sdl.mx < pos->x + env->editor.scale
			&& env->sdl.my > pos->y - env->editor.scale
			&& env->sdl.my < pos->y + env->editor.scale)
	{
		*scale = env->editor.scale * 3;
		if (click_on_grid_player(env))
		{
			reset_selection(env);
			env->editor.start_pos.x = env->player.pos.x;
			env->editor.start_pos.y = env->player.pos.y;
			env->editor.dragged_player = 1;
			tabs_gestion(env);
			check_event_creation(env);
		}
	}
	else
		*scale = env->editor.scale * 2.5;
}

void	draw_grid_player(t_env *env)
{
	t_point		pos;
	double		scale;

	if (env->editor.dragged_player == 1)
	{
		pos.x = env->sdl.mx;
		pos.y = env->sdl.my;
		scale = env->editor.scale * 3;
	}
	else
	{
		player_not_clicked(&pos, &scale, env);
	}
	draw_player_sprite(scale, pos, env);
}
