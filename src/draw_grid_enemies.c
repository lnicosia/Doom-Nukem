/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:55:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:20:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_enemy_angle(t_enemy *enemy, t_point pos, t_env *env)
{
	t_point	p;

	p = new_point(
		pos.x + cos(enemy->angle * CONVERT_RADIANS)
		* env->editor.scale * 2,
		pos.y + sin(enemy->angle * CONVERT_RADIANS)
		* env->editor.scale * 2);
	draw_line(pos, p, env, 0xFFFFFF00);
	pos = new_point(
		p.x + cos(enemy->angle * CONVERT_RADIANS
			- M_PI / 1.3) * env->editor.scale,
		p.y + sin(enemy->angle * CONVERT_RADIANS
			- M_PI / 1.3) * env->editor.scale);
	draw_line(pos, p, env, 0xFFFFFF00);
	pos = new_point(
		p.x + cos(enemy->angle * CONVERT_RADIANS
			+ M_PI / 1.3) * env->editor.scale,
		p.y + sin(enemy->angle * CONVERT_RADIANS
			+ M_PI / 1.3) * env->editor.scale);
	draw_line(pos, p, env, 0xFFFFFF00);
}

void	draw_enemy_sprite(int i, double scale, t_point center, t_env *env)
{
	t_point		size;
	t_sprite	*sprite;

	sprite = &env->enemy_sprites[env->enemies[i].sprite];
	size = new_point(scale,
	scale / (sprite->size[0].x / (double)sprite->size[0].y));
	draw_enemy_angle(&env->enemies[i], center, env);
	center = new_point(center.y - size.y / 2, center.x - size.x / 2);
	if (env->selected_enemy == i)
		apply_sprite_selected(env->enemy_sprites[env->enemies[i].sprite],
		center, size, env);
	else
		apply_sprite(env->enemy_sprites[env->enemies[i].sprite], center,
		size, env);
}

int		click_on_grid_enemy(t_env *env)
{
	if (env->inputs.left_click
			&& !env->confirmation_box.state
			&& !env->input_box.state
			&& env->editor.event_panel_dragged == -1
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_start_player == -1
			&& env->editor.dragged_enemy == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_object == -1
			&& !is_mouse_on_any_selection_tab(env)
			&& env->sdl.mx > 400)
		return (1);
	return (0);
}

void	draw_grid_enemy(int i, t_env *env)
{
	t_point		center;
	double		scale;

	center.x =
	env->enemies[i].pos.x * env->editor.scale + env->editor.center.x;
	center.y =
	env->enemies[i].pos.y * env->editor.scale + env->editor.center.y;
	if (env->sdl.mx > center.x - env->editor.scale
			&& env->sdl.mx < center.x + env->editor.scale
			&& env->sdl.my > center.y - env->editor.scale
			&& env->sdl.my < center.y + env->editor.scale)
	{
		scale = env->editor.scale * 2.5;
		if (click_on_grid_enemy(env))
		{
			reset_selection(env);
			env->editor.dragged_enemy = i;
			env->selected_enemy = i;
			tabs_gestion(env);
			check_event_creation(env);
		}
	}
	else
		scale = env->editor.scale * 2;
	draw_enemy_sprite(i, scale, center, env);
}

void	draw_grid_enemies(t_env *env)
{
	int			i;

	i = 0;
	while (i < env->nb_enemies)
	{
		draw_grid_enemy(i, env);
		i++;
	}
}
