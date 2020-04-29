#include "env.h"

void	edit_change_ceiling_height(t_env *env)
{
	t_sector	*sector;

	sector = &env->sectors[env->selected_ceiling];
	if (env->inputs.plus && !env->inputs.ctrl)
		env->sectors[env->selected_ceiling].ceiling +=
		(0.1 * (env->editor.key_delay / 500));
	if (env->inputs.minus && !env->inputs.ctrl)
		env->sectors[env->selected_ceiling].ceiling -=
		(0.1 * (env->editor.key_delay / 500));
	check_height_protections(env, sector);
	update_sector_slope(env, sector);
	update_player_z(env);
}

void	edit_change_floor_height(t_env *env)
{
	t_sector	*sector;

	sector = &env->sectors[env->selected_floor];
	if (env->inputs.plus && !env->inputs.ctrl)
		env->sectors[env->selected_floor].floor +=
		0.1 * (env->editor.key_delay / 500);
	else if (env->inputs.minus && !env->inputs.ctrl)
		env->sectors[env->selected_floor].floor -=
		0.1 * (env->editor.key_delay / 500);
	check_height_protections(env, sector);
	update_sector_slope(env, sector);
	update_player_z(env);	
}

void	change_ceiling_floor_height(t_env *env)
{
	if (env->editor.key_delay > INPUT_DELAY)
	{
		if (env->selected_ceiling != -1)
			edit_change_ceiling_height(env);
		else if (env->selected_floor != -1)
			edit_change_floor_height(env);
	}
}