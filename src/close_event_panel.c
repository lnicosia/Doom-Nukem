#include "env.h"

int		close_event_panel(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	if (env->editor.creating_condition)
	{
		if (env->editor.creating_launch_condition)
			env->editor.event_panel.launch_conditions_tab.state = DOWN;
		else
			env->editor.event_panel.exec_conditions_tab.state = DOWN;
		env->editor.creating_condition = 0;
		env->editor.creating_launch_condition = 0;
		env->editor.creating_exec_condition = 0;
		env->editor.selecting_condition_target = 0;
		env->editor.selecting_event = 0;
	}
	else
	{
		env->editor.creating_event = 0;
		env->editor.selecting_target = 0;
		env->editor.event_panel.selected_event = -1;
	}
	return (0);
}
