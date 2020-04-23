#include "env.h"

/*
**	Places editor tabs correctly
*/

int		general_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.general_tab.state = DOWN;
	env->editor.general_tab.anim_state = REST;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return(0);
}

int		sector_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return (0);
}

int		sprite_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.sprite_tab.state = DOWN;
	env->editor.sprite_tab.anim_state = PRESSED;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return (0);
}

int		events_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	return (0);
}

void	tabs_gestion(t_env *env)
{
	if (env->editor.sprite_tab.state == UP
	&& env->editor.sector_tab.state == UP
	&& env->editor.events_tab.state == UP
	&& env->selected_wall_sprite_sprite == -1)
		general_tab(env);
	if (env->selected_wall_sprite_sprite != -1
		|| env->selected_ceiling_sprite != -1
		|| env->selected_floor_sprite != -1)
		sprite_tab(env);
	new_tabs_position(env);
}
