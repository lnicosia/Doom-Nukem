#include "env.h"

int		check_ceiling_slope_input_box3(t_sector *sector, double prec,
t_env *env)
{
	int			i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == sector->num
			&& env->enemies[i].pos.z + env->enemies[i].scale >=
			get_ceiling_at_pos(sector, env->enemies[i].pos, env))
		{
			sector->ceiling_slope = prec;
			update_sector_slope(env, sector);
			return (1);
		}
		i++;
	}
	sector->ceiling_slope = prec;
	update_sector_slope(env, sector);
	return (0);
}

int		check_ceiling_slope_input_box2(t_sector *sector, double prec,
t_env *env)
{
	double		z;

	if (env->player.sector == sector->num)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
		{
			sector->ceiling_slope = prec;
			update_sector_slope(env, sector);
			return (1);
		}
	}
	return (check_ceiling_slope_input_box3(sector, prec, env));
}

int		check_ceiling_slope_input_box(void *penv)
{
	t_env		*env;
	t_sector	*sector;
	double		prec;

	env = (t_env*)penv;
	if (env->editor.selected_sector != -1)
		sector = &env->sectors[env->editor.selected_sector];
	else
		sector = &env->sectors[env->selected_ceiling];
	prec = sector->ceiling_slope;
	sector->ceiling_slope = ft_atof(env->input_box.str);
	update_sector_slope(env, sector);
	if (sector->floor_max > sector->ceiling_min)
	{
		sector->ceiling_slope = prec;
		update_sector_slope(env, sector);
		return (1);
	}
	return (check_ceiling_slope_input_box2(sector, prec, env));
}
