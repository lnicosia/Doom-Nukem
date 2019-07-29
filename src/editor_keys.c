/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/29 18:38:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			editor_keys(t_env *env)
{
	int		clicked_vertex;

	if (env->inputs.space)
	{
		clicked_vertex = get_existing_vertex(env);
		if (clicked_vertex == -1)
		{
			if (add_vertex(env))
				return (ft_printf("Could not add new vertex\n"));
			if (!env->editor.new_sector) //Nouveau secteur
				env->editor.new_sector = 1;
			add_vertex_to_current_sector(env, env->nb_vertices - 1);
		}
		else
		{
			if (!env->editor.new_sector)
			{
				env->editor.new_sector = 1;
				add_vertex_to_current_sector(env, clicked_vertex);
			}
			else
			{
				if (clicked_vertex == ((t_vertex*)env->editor.current_vertices->content)->num)
				{
					env->editor.reverted = get_clockwise_order(env) ? 0 : 1;
					env->editor.new_sector = 0;
					if (add_sector(env))
						return (ft_printf("Error while creating new sector\n"));
					free_current_vertices(env);
				}
				else
					add_vertex_to_current_sector(env, clicked_vertex);
			}
		}
		env->inputs.space = 0;
	}
	if (env->inputs.left_click
			&& env->sdl.mx > 130
			&& env->sdl.mx < 170
			&& env->sdl.my > 280
			&& env->sdl.my < 320
			&& !env->drawing)
	{
		env->editor.new_player = 1;
		env->editor.drag = 1;
	}
	if (!env->inputs.left_click && env->editor.drag)
	{
		env->editor.drag = 0;
		add_player(env);
	}
	if (env->inputs.right_click)
	{
		env->editor.center.x += env->sdl.mouse_x;
		env->editor.center.y += env->sdl.mouse_y;
	}
	if (env->inputs.enter && env->nb_sectors)
	{
		env->player.pos.x = 0;
		env->player.pos.y = 0;
		env->player.pos.z = 0;
		env->player.angle = 0;
		env->player.angle_z = 0;
		env->player.angle_cos = cos(env->player.angle);
		env->player.angle_cos = sin(env->player.angle);
		env->player.perp_cos = cos(env->player.angle - M_PI / 2);
		env->player.perp_sin = sin(env->player.angle - M_PI / 2);
		env->player.sector = 0;
		env->editor.in_game = 1;
		env->inputs.enter = 0;
		if (init_screen_pos(env))
			return (ft_printf("Could not init screen pos\n"));
		update_camera_position(env);
		update_player_z(env);
		update_floor(env);
		SDL_SetRelativeMouseMode(1);
	}
	return (0);
}
