/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_buttons_functions2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:01:28 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:01:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_brightness_or_intensity(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.check = &check_light_data_input_box;
	env->input_box.update = &update_sector_entities_light_input_box;
	env->input_box.error_message = "Error: brightness/intensity must be"
	" between -256 and 256";
	return (0);
}

int		change_color(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.update = &update_sector_entities_light_input_box;
	env->input_box.error_message = "Error: color must be an hexa ARGB color";
	return (0);
}

int		change_gravity(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.check = &check_gravity_input_box;
	env->input_box.error_message = "Error: gravity must be 0 or"
	" between -1 and -10";
	return (0);
}

int		change_texture_scale(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.check = &check_texture_scale_input_box;
	env->input_box.update = &update_wall_texture_button;
	env->input_box.error_message = "Error: scale must be between 1 and 100";
	return (0);
}

int		change_enemy_scale(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.check = &check_entities_sprite_scale_input_box;
	env->input_box.error_message = "Error: scale must be between 0.1 and 100"
	". The enemy must fit in its sector";
	return (0);
}
