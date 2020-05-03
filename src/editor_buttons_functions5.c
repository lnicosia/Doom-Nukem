/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_buttons_functions5.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:02:24 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:02:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
