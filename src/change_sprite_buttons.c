/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite_buttons.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:28:42 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/03 16:07:54 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_ceiling_sprite(t_button_next *button)
{
	t_env *env;

	env = button->env;
	if (button->button_type == PREVIOUS)
	{
		if (env->selected_ceiling_sprite > 0)
			env->selected_ceiling_sprite--;
		else
			env->selected_ceiling_sprite =
			env->sectors[env->selected_ceiling].ceiling_sprites.nb_sprites - 1;
		env->editor.previous_sprite.state = UP;
		env->editor.previous_sprite.anim_state = REST;
	}
	else if (button->button_type == NEXT)
	{
		if (env->selected_ceiling_sprite <
			env->sectors[env->selected_ceiling].ceiling_sprites.nb_sprites - 1)
			env->selected_ceiling_sprite++;
		else
			env->selected_ceiling_sprite = 0;
		env->editor.next_sprite.state = UP;
		env->editor.next_sprite.anim_state = REST;
	}
	return (0);
}

int		change_floor_sprite(t_button_next *button)
{
	t_env *env;

	env = button->env;
	if (button->button_type == PREVIOUS)
	{
		if (env->selected_floor_sprite > 0)
			env->selected_floor_sprite--;
		else
			env->selected_floor_sprite =
			env->sectors[env->selected_floor].floor_sprites.nb_sprites - 1;
		env->editor.previous_sprite.state = UP;
		env->editor.previous_sprite.anim_state = REST;
	}
	else if (button->button_type == NEXT)
	{
		if (env->selected_floor_sprite <
			env->sectors[env->selected_floor].floor_sprites.nb_sprites - 1)
			env->selected_floor_sprite++;
		else
			env->selected_floor_sprite = 0;
		env->editor.next_sprite.state = UP;
		env->editor.next_sprite.anim_state = REST;
	}
	return (0);
}

int		change_wall_sprite(t_button_next *button)
{	
	t_env *env;

	env = button->env;
	if (button->button_type == PREVIOUS)
	{
		if (env->selected_wall_sprite_sprite > 0)
			env->selected_wall_sprite_sprite--;
		else
			env->selected_wall_sprite_sprite =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].nb_sprites - 1;
		env->editor.previous_sprite.state = UP;
		env->editor.previous_sprite.anim_state = REST;
	}
	else if (button->button_type == NEXT)
	{
		if (env->selected_wall_sprite_sprite <
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].nb_sprites - 1)
			env->selected_wall_sprite_sprite++;
		else
			env->selected_wall_sprite_sprite = 0;
		env->editor.next_sprite.state = UP;
		env->editor.next_sprite.anim_state = REST;
	}
	return (0);
}

int		change_sprite(void *target)
{
	t_button_next	*button;
	t_env			*env;
	 
	env = (t_env *)target;
	button = NULL;
	if (env->editor.next_sprite.state == DOWN)
		button = &env->editor.next_sprite_env;
	else if (env->editor.previous_sprite.state == DOWN)
		button = &env->editor.previous_sprite_env;
	if (button->type == WALL_S)
		change_wall_sprite(button);
	else if (button->type == FLOOR_S)
		change_floor_sprite(button);
	else if (button->type == CEILING_S)
		change_ceiling_sprite(button);
	return (0);
}
