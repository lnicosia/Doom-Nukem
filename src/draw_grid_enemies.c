/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:55:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/06 15:02:48 by lnicosia         ###   ########.fr       */
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
	draw_line(pos, p, *env, 0xFFFFFF00);
	pos = new_point(
		p.x + cos(enemy->angle * CONVERT_RADIANS
			- M_PI / 1.3) * env->editor.scale,
		p.y + sin(enemy->angle * CONVERT_RADIANS
			- M_PI / 1.3) * env->editor.scale);
	draw_line(pos, p, *env, 0xFFFFFF00);
	pos = new_point(
		p.x + cos(enemy->angle * CONVERT_RADIANS
			+ M_PI / 1.3) * env->editor.scale,
		p.y + sin(enemy->angle * CONVERT_RADIANS
			+ M_PI / 1.3) * env->editor.scale);
	draw_line(pos, p, *env, 0xFFFFFF00);
}

void	draw_grid_enemies(t_env *env)
{
	t_point		center;
	t_point		size;
	t_sprite	sprite;
	double		scale;
	int			i;

	i = 0;
	while (i < env->nb_enemies)
	{
		center.x =
		env->enemies[i].pos.x * env->editor.scale + env->editor.center.x;
		center.y =
		env->enemies[i].pos.y * env->editor.scale + env->editor.center.y;
		sprite = env->enemy_sprites[env->enemies[i].sprite];
		if (env->sdl.mx > center.x - env->editor.scale
				&& env->sdl.mx < center.x + env->editor.scale
				&& env->sdl.my > center.y - env->editor.scale
				&& env->sdl.my < center.y + env->editor.scale)
		{
			scale = env->editor.scale * 2.5;
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
		size = new_point(scale,
		scale / (sprite.size[0].x / (double)sprite.size[0].y));
		draw_enemy_angle(&env->enemies[i], center, env);
		center = new_point(center.y - size.y / 2, center.x - size.x / 2);
		if (env->selected_enemy == i)
			apply_sprite_selected(env->enemy_sprites[env->enemies[i].sprite],
			center, size, env);
		else
			apply_sprite(env->enemy_sprites[env->enemies[i].sprite], center,
			size, env);
		i++;
	}
}