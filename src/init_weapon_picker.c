#include "env.h"

int		weapon_picker_ok(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.selected_weapon = env->editor.current_weapon;
	check_event_creation(env);
	if (env->editor.selecting_weapon)
	{
		env->editor.selecting_weapon = 0;
		env->editor.creating_event = 1;
	}
	else if (env->editor.selecting_condition_weapon)
	{
		env->editor.selecting_condition_weapon = 0;
		env->editor.creating_condition = 1;
	}
	return (0);
}

int		weapon_picker_cancel(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (env->editor.selecting_weapon)
	{
		env->editor.selecting_weapon = 0;
		env->editor.creating_event = 1;
	}
	else if (env->editor.selecting_condition_weapon)
	{
		env->editor.selecting_condition_weapon = 0;
		env->editor.creating_condition = 1;
	}
	return (0);
}

int		next_weapon(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (env->editor.current_weapon == NB_WEAPONS - 1)
		env->editor.current_weapon = 0;
	else
		env->editor.current_weapon++;
	return (0);
}

int		previous_weapon(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (env->editor.current_weapon == 0)
		env->editor.current_weapon = NB_WEAPONS - 1;
	else
		env->editor.current_weapon--;
	return (0);
}

void	init_weapon_picker(t_env *env)
{
	env->editor.weapon_picker.size = new_point(600, 300);
	env->editor.weapon_picker.pos =
	new_point(env->h_w - env->editor.weapon_picker.size.x / 2,
	env->h_h - env->editor.weapon_picker.size.y / 2);
	env->editor.weapon_picker.next = new_next_arrow(ON_RELEASE, &next_weapon,
	env, env);
	env->editor.weapon_picker.previous = new_previous_arrow(ON_RELEASE,
	&previous_weapon, env, env);
	env->editor.weapon_picker.next.pos = new_point(
	env->editor.weapon_picker.pos.x + env->editor.weapon_picker.size.x
	- env->editor.weapon_picker.next.size_up.x - 20,
	env->editor.weapon_picker.pos.y + env->editor.weapon_picker.size.y / 2
	+ env->editor.event_panel.top_size / 2
	- env->editor.weapon_picker.next.size_up.y / 2);
	env->editor.weapon_picker.previous.pos = new_point(
	env->editor.weapon_picker.pos.x + 20,
	env->editor.weapon_picker.next.pos.y);
	env->editor.weapon_picker.ok = env->editor.event_panel.ok;
	env->editor.weapon_picker.ok.release_action = &weapon_picker_ok;
	env->editor.weapon_picker.ok.pos = new_point(env->editor.weapon_picker.pos.x
	+ env->editor.weapon_picker.size.x - 198, env->editor.weapon_picker.pos.y);
	env->editor.weapon_picker.cancel = env->editor.event_panel.cancel;
	env->editor.weapon_picker.cancel.release_action = &weapon_picker_cancel;
	env->editor.weapon_picker.cancel.pos =
	new_point(env->editor.weapon_picker.ok.pos.x + 100,
	env->editor.weapon_picker.pos.y);
}
