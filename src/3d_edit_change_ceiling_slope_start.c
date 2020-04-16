#include "env.h"

int		increase_ceiling_slope_start(t_env *env)
{
	env->sectors[env->selected_ceiling].start_ceiling_slope++;
	env->sectors[env->selected_ceiling].ceiling_normal =
	get_sector_normal(&env->sectors[env->selected_ceiling], env,
	env->sectors[env->selected_ceiling].start_ceiling_slope);
	update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	if (check_entities_height(env))
	{
		env->sectors[env->selected_ceiling].start_ceiling_slope--;
		env->sectors[env->selected_ceiling].ceiling_normal =
		get_sector_normal(&env->sectors[env->selected_ceiling], env,
		env->sectors[env->selected_ceiling].start_ceiling_slope);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		return (update_confirmation_box(&env->confirmation_box,
		"An entity position will be outside the map", ERROR, env));
	}
	return (0);
}

int		decrease_ceiling_slope_start(t_env *env)
{
	env->sectors[env->selected_ceiling].start_ceiling_slope--;
	env->sectors[env->selected_ceiling].ceiling_normal =
	get_sector_normal(&env->sectors[env->selected_ceiling], env,
	env->sectors[env->selected_ceiling].start_ceiling_slope);
	update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	if (check_entities_height(env))
	{
		env->sectors[env->selected_ceiling].start_ceiling_slope++;
		env->sectors[env->selected_ceiling].ceiling_normal =
		get_sector_normal(&env->sectors[env->selected_ceiling], env,
		env->sectors[env->selected_ceiling].start_ceiling_slope);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		return (update_confirmation_box(&env->confirmation_box,
		"An entity position will be outside the map", ERROR, env));
	}
	return (0);
}

int		change_ceiling_slope_start(t_env *env)
{
	if ((env->inputs.left || env->sdl.event.key.keysym.sym == SDLK_LEFT)
	&& env->sectors[env->selected_ceiling].start_ceiling_slope
	< env->sectors[env->selected_ceiling].nb_vertices - 1)
		return (increase_ceiling_slope_start(env));
	else if ((env->inputs.right || env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	&& env->sectors[env->selected_ceiling].start_ceiling_slope > 0)
		return (decrease_ceiling_slope_start(env));
	return (0);
}
