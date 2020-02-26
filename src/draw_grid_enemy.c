/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:55:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 10:49:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


void	draw_grid_enemies(t_env *env)
{
	t_point		center;
	t_point		size;
	double		scale;
	int			i;
	Uint32		color;
	t_texture	texture;

	i = 0;
	if (env->editor.dragged_enemy != -1)
	{
		color = 0xFF0000FF;
		scale = env->editor.scale / 2.0;
		center.x = env->sdl.mx;
		center.y = env->sdl.my;
		draw_circle(new_circle(color, color, center, scale), env);
		texture =
		env->sprite_textures[env->enemies[env->editor.dragged_enemy].sprite];
		apply_image_selected(texture, center, new_point(texture.surface->w,
		texture.surface->h), env);
	}
	while (i < env->nb_enemies)
	{
		center.x = env->enemies[i].pos.x * env->editor.scale + env->editor.center.x;
		center.y = env->enemies[i].pos.y * env->editor.scale + env->editor.center.y;
		if (env->sdl.mx > center.x - env->editor.scale / 2.0
				&& env->sdl.mx < center.x + env->editor.scale / 2.0
				&& env->sdl.my > center.y - env->editor.scale / 2.0
				&& env->sdl.my < center.y + env->editor.scale / 2.0)
		{
			scale = env->editor.scale;
			color = 0xFF0000FF;
			if (env->inputs.left_click
					&& !env->confirmation_box.state
					&& !env->input_box.state
					&& env->editor.event_panel_dragged == -1
					&& env->editor.start_vertex == -1
					&& env->editor.dragged_player == -1
					&& env->editor.dragged_enemy == -1
					&& env->editor.dragged_vertex == -1
					&& env->editor.dragged_object == -1
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
		{
			color = 0xFF0000FF;
			scale = env->editor.scale / 2.0;
		}
		texture = env->mini_enemies_textures[get_main_enemy_sprite(
		env->enemies[i].sprite, env)];
		size = new_point(env->editor.scale * 2, env->editor.scale * 2);
		center = new_point(center.y - size.y / 2, center.x - size.x / 2);
		//texture = env->sprite_textures[32];
			//color = 0xFF0000FF;
		if (env->editor.dragged_enemy != i)
		{
			size.x /= 1.3;
			size.y /= 1.3;
		}
			//draw_circle(new_circle(color, color, center, scale), env);
		if (env->selected_enemy == i)
			apply_image_selected(texture, center, size, env);
		else
			apply_image(texture, center, size, env);
		i++;
	}
}
