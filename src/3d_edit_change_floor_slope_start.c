#include "env.h"

int		increase_floor_slope_start(t_env *env)
{
	env->sectors[env->selected_floor].start_floor_slope++;
	env->sectors[env->selected_floor].floor_normal =
	get_sector_normal(&env->sectors[env->selected_floor], env,
	env->sectors[env->selected_floor]. start_floor_slope);
	update_sector_slope(env, &env->sectors[env->selected_floor]);
	if (check_entities_height(env))
	{
		env->sectors[env->selected_floor].start_floor_slope--;
		env->sectors[env->selected_floor].floor_normal =
		get_sector_normal(&env->sectors[env->selected_floor], env,
		env->sectors[env->selected_floor]. start_floor_slope);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		return (update_confirmation_box(&env->confirmation_box,
		"An entity position will be outside the map", ERROR, env));
	}
	return (0);
}

int		decrease_floor_slope_start(t_env *env)
{
	env->sectors[env->selected_floor].start_floor_slope--;
	env->sectors[env->selected_floor].floor_normal =
	get_sector_normal(&env->sectors[env->selected_floor], env,
	env->sectors[env->selected_floor]. start_floor_slope);
	update_sector_slope(env, &env->sectors[env->selected_floor]);
	if (check_entities_height(env))
	{
		env->sectors[env->selected_floor].start_floor_slope++;
		env->sectors[env->selected_floor].floor_normal =
		get_sector_normal(&env->sectors[env->selected_floor], env,
		env->sectors[env->selected_floor]. start_floor_slope);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		return (update_confirmation_box(&env->confirmation_box,
		"An entity position will be outside the map", ERROR, env));
	}
	return (0);
}

int		change_floor_slope_start(t_env *env)
{
	if ((env->inputs.left || env->sdl.event.key.keysym.sym == SDLK_LEFT)
	&& env->sectors[env->selected_floor].start_floor_slope
	< env->sectors[env->selected_floor].nb_vertices - 1)
	  	return (increase_floor_slope_start(env));
	else if ((env->inputs.right || env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	&& env->sectors[env->selected_floor].start_floor_slope > 0)
	  	return (decrease_floor_slope_start(env));
	return (0);
}
