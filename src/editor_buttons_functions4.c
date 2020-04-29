#include "env.h"

int		change_floor_sprite_scale(void *param)
{
	t_button_tab    *button;
	t_env                   *env;

	button = (t_button_tab *)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_sprite_scale_input_box;
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
	env->input_box.check = &check_texture_scale_input_box;
	env->input_box.update = &update_ceiling_texture_button;
	env->input_box.error_message = "Error: scale must be between 1 and 100";
	return (0);
}

int		change_floor_texture_scale(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab*)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_texture_scale_input_box;
	env->input_box.update = &update_floor_texture_button;
	env->input_box.error_message = "Error: scale must be between 1 and 100";
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