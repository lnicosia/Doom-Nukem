#include "env.h"

int		add_object_button(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.create_object = 1;
	if (!env->editor.draw_object_tab)
		env->editor.create_object = 1;
	else
		env->editor.add_object.state = UP;
		env->editor.add_object.anim_state = REST;
	return (0);
}

int		add_enemy_button(void *target)
{
	t_env *env;

	env = (t_env *)target;
	if (!env->editor.draw_enemy_tab)
		env->editor.create_enemy = 1;
	else
		env->editor.add_object.state = UP;
		env->editor.add_object.anim_state = REST;
	return (0);
}

int		open_enemy_selection(void *param)
{
	t_env *env;

	env = (t_env *)param;
	env->editor.draw_enemy_tab = 1;
	return (0);
}

int		open_object_selection(void *param)
{
	t_env *env;

	env = (t_env *)param;
	env->editor.draw_object_tab = 1;
	return (0);
}

int		open_texture_selection(void *param)
{
	t_env *env;

	env = (t_env *)param;
	env->editor.draw_texture_tab = 1;
	return (0);
}
