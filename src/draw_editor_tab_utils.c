/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor_tab_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:23:33 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 22:23:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int draw_wall_sprites_general_buttons(t_env *env)
{
    if (env->selected_floor_sprite != -1
	|| env->selected_wall_sprite_sprite != -1
		|| env->selected_ceiling_sprite != -1)
	{
		if (draw_button(env, env->editor.next_sprite,
			env->editor.next_sprite.str))
			return (-1);
		if (draw_button(env, env->editor.previous_sprite,
		env->editor.previous_sprite.str))
			return (-1);
		if (draw_button(env, env->editor.sprite_background,
		env->editor.sprite_background.str))
			return (-1);
		apply_sprite(env->object_sprites[env->editor.current_sprite],
		new_point(env->editor.current_sprite_selection.pos.y,
		env->editor.current_sprite_selection.pos.x),
		new_point(60, 60), env);
	}
    return (0);
}

int draw_editor_general_tab(t_env *env)
{
    if (((env->selected_ceiling_sprite == -1
	&& env->selected_floor_sprite == -1
	&& env->selected_wall_sprite_sprite == -1)
	&& (env->selected_object != -1 || env->editor.selected_wall != -1 ||
	env->selected_floor != -1 || env->selected_enemy != -1
	|| env->selected_ceiling != -1))
	|| ((env->editor.selected_sector != -1
	|| env->editor.selected_start_player != -1
	|| env->selected_object != -1 || env->selected_enemy != -1
	|| env->editor.selected_vertex != -1)))
	{
		if (draw_button(env, env->editor.general_tab,
			env->editor.general_tab.str))
			return (-1);
	}
    return (0);
}