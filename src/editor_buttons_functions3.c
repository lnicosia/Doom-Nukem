#include "env.h"

int		change_enemy_damage(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_damage_input_box;
	env->input_box.error_message = "Error: damage must be between 0 and 100";
	return (0);
}

int		change_object_scale(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_entities_sprite_scale_input_box;
	env->input_box.error_message = "Error: scale must be between 0.1 and 100";
	return (0);
}

int		change_object_damage(void *param)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_damage_input_box;
	env->input_box.error_message = "Error: damage must be between 0 and 100";
	return (0);
}

int		change_wall_sprite_scale(void *param)
{
	t_button_tab    *button;
	t_env                   *env;

	button = (t_button_tab *)param;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	env->input_box.check = &check_sprite_scale_input_box;
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
	env->input_box.check = &check_sprite_scale_input_box;
	env->input_box.update = &update_ceiling_sprite_scale_input_box;
	env->input_box.error_message = "Error: scale must be between 0.1 and 100";
	return (0);
}
