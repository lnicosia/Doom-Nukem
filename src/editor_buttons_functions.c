/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_buttons_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:10:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 15:38:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_floor_slope(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
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
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.check = &check_health_input_box;
	env->input_box.error_message = "Error: health must be between 1 and 10000";
	return (0);
}

int		change_player_speed(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.check = &check_player_speed_input_box;
	env->input_box.error_message = "Error: speed must be between 0 and 1";
	return (0);
}

int		change_enemy_speed(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.check = &check_enemy_speed_input_box;
	env->input_box.error_message = "Error: speed must be between 0 and 100";
	return (0);
}

int		change_angle(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	if (new_input_var(&env->input_box, button->pos, button->type,
		button->target))
		return (-1);
	env->input_box.check = &check_angle_input_box;
	env->input_box.error_message = "Error: angle must be between 0 and 360";
	return (0);
}
