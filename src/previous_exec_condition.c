#include "env.h"

int		previous_exec_condition3(t_env *env)
{
	if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		if (env->editor.selected_events == 0)
			env->editor.selected_exec_condition =
			env->sectors[env->editor.selected_sector].
			stand_events[env->editor.selected_event].
			nb_exec_conditions - 1;
		else if (env->editor.selected_events == 1)
			env->editor.selected_exec_condition =
			env->sectors[env->editor.selected_sector].
			walk_in_events[env->editor.selected_event].
			nb_exec_conditions - 1;
		else if (env->editor.selected_events == 2)
			env->editor.selected_exec_condition =
			env->sectors[env->editor.selected_sector].
			walk_out_events[env->editor.selected_event].
			nb_exec_conditions - 1;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->selected_enemy == -1 && env->selected_object == -1)
		env->editor.selected_exec_condition =
		env->global_events[env->editor.selected_event].nb_exec_conditions - 1;
	return (0);
}

int		previous_exec_condition2(t_env *env)
{
	if (env->selected_object != -1)
		env->editor.selected_exec_condition = env->objects[env->
		selected_object].collision_events[env->editor.selected_event].
		nb_exec_conditions - 1;
	else if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0)
			env->editor.selected_exec_condition =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].
			press_events[env->selected_wall_sprite_sprite]
			[env->editor.selected_event].nb_exec_conditions - 1;
		else if (env->editor.selected_events == 1)
			env->editor.selected_exec_condition =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].
			shoot_events[env->selected_wall_sprite_sprite]
			[env->editor.selected_event].nb_exec_conditions - 1;
	}
	return (previous_exec_condition3(env));
}

int		previous_exec_condition(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->editor.selected_exec_condition > 0)
		env->editor.selected_exec_condition--;
	else
	{
		if (env->selected_enemy != -1)
		{
			if (env->editor.selected_events == 0)
				env->editor.selected_exec_condition = env->enemies[env->
				selected_enemy].collision_events[env->editor.selected_event].
				nb_exec_conditions - 1;
			else if (env->editor.selected_events == 1)
				env->editor.selected_exec_condition = env->enemies[env->
				selected_enemy].death_events[env->editor.selected_event].
				nb_exec_conditions - 1;
		}
		return (previous_exec_condition2(env));
	}
	return (0);
}
