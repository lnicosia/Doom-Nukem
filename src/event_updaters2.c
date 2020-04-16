#include "env.h"

t_event_param	new_event_param(int num, double equ_value, double diff_value)
{
	t_event_param	new;

	ft_bzero(&new, sizeof(new));
	new.num = num;
	new.equ_value = equ_value;
	new.diff_value = diff_value;
	return (new);
}

t_event_param	empty_event_param(void)
{
	t_event_param	new;

	ft_bzero(&new, sizeof(new));
	return (new);
}

int			update_player_pos_event(t_event *event, void *penv)
{
	(void)event;
	update_player_pos((t_env*)penv);
	return (0);
}

int			update_player_z_event(t_event *event, void *penv)
{
	t_env	*env;

	(void)event;
	env = ((t_env*)penv);
	update_player_pos(env);
	env->player.pos.z = get_floor_at_pos(&env->sectors[env->player.sector],
	env->player.pos, env);
	update_player_pos(env);
	return (0);
}

int			update_player_event(t_event *event, void *penv)
{
	(void)event;
	update_player_pos((t_env*)penv);
	return (0);
}
