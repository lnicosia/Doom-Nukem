#include "env.h"

int		check_condition_validity(t_env *env, t_condition condition)
{
	if (!condition.target)
	{
		if (update_confirmation_box(&env->confirmation_box, "Please set a"
			" target before saving the condition", ERROR, env))
			return (-1);
		return (1);
	}
	return (0);
}

void	save_condition_value(t_condition *condition, t_condition_panel *panel)
{
	if (condition->target_type == INT)
		condition->value = panel->int_value;
	else if (condition->target_type == DOUBLE)
		condition->value = panel->double_value;
	else if (condition->target_type == UINT32)
		condition->value = panel->uint32_value;
}
