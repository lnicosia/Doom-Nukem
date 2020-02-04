/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_buttons_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:10:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 09:23:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_brightness_or_intensity(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
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
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.update = &update_sector_entities_light_input_box;
	env->input_box.error_message = "Error: brightness/intensity must be"
	" between -256 and 256";
	return (0);
}

int		change_gravity(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_gravity_input_box;
	env->input_box.error_message = "Error: gravity must be between -0.1 and"
	" -10";
	return (0);
}

int		change_wall_texture_scale(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_scale_input_box;
	env->input_box.error_message = "Error: scale must be between 0.1 and 100";
	return (0);
}

int		change_ceiling_sprite_scale(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_scale_input_box;
	env->input_box.update = &update_ceiling_sprite_scale_input_box;
	env->input_box.error_message = "Error: scale must be between 0.1 and 100";
	return (0);
}

int		change_floor_sprite_scale(void *param)
{
        t_button_tab    *button;
        t_env                   *env;

        button = (t_button_tab *)param;
        env = button->env;
        new_input_var(&env->input_box, button->pos, button->type, button->target);
        env->input_box.check = &check_scale_input_box;
        env->input_box.update = &update_floor_sprite_scale_input_box;
        env->input_box.error_message = "Error: scale must be between 0.1 and 100";
        return (0);
}

int		change_ceiling_texture_scale(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_scale_input_box;
	env->input_box.update = &update_ceiling_texture_button;
	env->input_box.error_message = "Error: scale must be between 0.1 and 100";
	return (0);
}

int		change_floor_texture_scale(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_scale_input_box;
	env->input_box.update = &update_floor_texture_button;
	env->input_box.error_message = "Error: scale must be between 0.1 and 100";
	return (0);
}

int		change_ceiling_texture_align(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.update = &update_ceiling_texture_button;
	return (0);
}

int		change_floor_texture_align(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.update = &update_floor_texture_button;
	return (0);
}

int		change_ceiling_height(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_ceiling_height_input_box;
	env->input_box.update = &update_sector_input_box;
	env->input_box.error_message = "Error: ceiling is too low";
	return (0);
}

int		change_floor_height(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_floor_height_input_box;
	env->input_box.update = &update_sector_input_box;
	env->input_box.error_message = "Error: floor is too high";
	return (0);
}

int		change_ceiling_slope(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_ceiling_slope_input_box;
	env->input_box.update = &update_sector_input_box;
	env->input_box.error_message = "Error: ceiling slope is invalid";
	return (0);
}

int		change_floor_slope(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_floor_slope_input_box;
	env->input_box.update = &update_sector_input_box;
	env->input_box.error_message = "Error: floor slope is invalid";
	return (0);
}

int		change_health(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_health_input_box;
	env->input_box.error_message = "Error: health must be between 1 and 10000";
	return (0);
}

int		change_speed(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_speed_input_box;
	env->input_box.error_message = "Error: speed must be between 0 and 100";
	return (0);
}
