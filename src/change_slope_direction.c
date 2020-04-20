#include "env.h"

void	change_floor_slope_direction(t_button_next *button, t_env *env)
{
	t_sector		*sector;

	sector = &env->sectors[env->selected_floor];
	if (button->button_type == NEXT)
	{
		sector->start_floor_slope++;
		if (sector->start_floor_slope > sector->nb_vertices - 1)
			sector->start_floor_slope = 0;
	}
	else if (button->button_type == PREVIOUS)
	{
		sector->start_floor_slope--;
		if (sector->start_floor_slope < 0)
			sector->start_floor_slope = sector->nb_vertices - 1;
	}
	env->sectors[env->selected_floor].floor_normal =
	get_sector_normal(&env->sectors[env->selected_floor], env,
	env->sectors[env->selected_floor]. start_floor_slope);
	update_sector_slope(env, &env->sectors[env->selected_floor]);
	update_player_z(env);
}

void	change_ceiling_slope_direction(t_button_next *button, t_env *env)
{
	t_sector		*sector;

	sector = &env->sectors[env->selected_ceiling];
	if (button->button_type == NEXT)
	{
		sector->start_ceiling_slope++;
		if (sector->start_ceiling_slope > sector->nb_vertices - 1)
			sector->start_ceiling_slope = 0;
	}
	else if (button->button_type == PREVIOUS)
	{
		sector->start_ceiling_slope--;
		if (sector->start_ceiling_slope > 0)
			sector->start_ceiling_slope = sector->nb_vertices - 1;
	}
	env->sectors[env->selected_ceiling].ceiling_normal =
	get_sector_normal(&env->sectors[env->selected_ceiling],
	env, env->sectors[env->selected_ceiling].start_ceiling_slope);
	update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	update_player_z(env);
}

int		change_slope_direction(void *target)
{
	t_env			*env;
	t_button_next	*button;
	
	button = NULL;
	env = (t_env *)target;
	if (env->editor.next_slope_swap.state == DOWN)
		button = &env->editor.next_slope_swap_env;
	if (env->editor.previous_slope_swap.state == DOWN)
		button = &env->editor.previous_slope_swap_env;
	if (env->selected_ceiling != -1)
	{
	  	change_ceiling_slope_direction(button, env);
	}
	else if (env->selected_floor != -1)
	{
	  	change_floor_slope_direction(button, env);
	}
	env->editor.previous_slope_swap.state = UP;
	env->editor.previous_slope_swap.anim_state = REST;
	env->editor.next_slope_swap.state = UP;
	env->editor.next_slope_swap.anim_state = REST;
	return (0);
}
