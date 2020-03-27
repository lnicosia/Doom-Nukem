#include "env.h"

int		new_condition_target(t_env *env)
{
	env->editor.creating_event = 1;
	env->editor.creating_condition = 1;
	env->editor.selecting_condition_target = 0;
	env->editor.condition_panel.target_tab.anim_state = REST;
	env->editor.condition_panel.target_tab.state = UP;
	set_new_condition_target(env);
	if (env->editor.condition_panel.condition.target)
		set_condition_buttons_state(env);
	return (0);
}

int		new_event_target(t_env *env)
{
	env->editor.creating_event = 1;
	env->editor.selecting_target = 0;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = DOWN;
	set_new_event_target(env);
	env->editor.event_panel.action_panel.double_value = 0;
	env->editor.event_panel.action_panel.int_value = 0;
	env->editor.event_panel.action_panel.uint32_value = 0;
	if (env->editor.event_panel.event.target_index != -1)
		set_buttons_state(env);
	return (0);
}
