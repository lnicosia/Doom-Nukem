#include "env.h"
#include "events_conditions.h"

void	set_condition_panel_buttons_state2(t_env *env, int type)
{
	if (type == EQUALS)
		env->editor.condition_panel.equals.state = DOWN;
	if (type == DIFFERENT)
		env->editor.condition_panel.different.state = DOWN;
	if (type == LESS)
		env->editor.condition_panel.less.state = DOWN;
	if (type == GREATER)
		env->editor.condition_panel.greater.state = DOWN;
	if (type == LESS_OR_EQUALS)
		env->editor.condition_panel.less_or_equals.state = DOWN;
	if (type == GREATER_OR_EQUALS)
		env->editor.condition_panel.greater_or_equals.state = DOWN;
	if (type == EVENT_ENDED)
		env->editor.condition_panel.event_ended.state = DOWN;
	if (type == EVENT_ENDED_START)
		env->editor.condition_panel.event_ended_start.state = DOWN;
	if (type == FUNCTION)
		env->editor.condition_panel.function.state = DOWN;
}

void	set_condition_panel_buttons_state(t_env *env, int type)
{
	env->editor.condition_panel.equals.state = UP;
	env->editor.condition_panel.different.state = UP;
	env->editor.condition_panel.less.state = UP;
	env->editor.condition_panel.greater.state = UP;
	env->editor.condition_panel.less_or_equals.state = UP;
	env->editor.condition_panel.greater_or_equals.state = UP;
	env->editor.condition_panel.event_ended.state = UP;
	env->editor.condition_panel.event_ended_start.state = UP;
	env->editor.condition_panel.function.state = UP;
	set_condition_panel_buttons_state2(env, type);
}
