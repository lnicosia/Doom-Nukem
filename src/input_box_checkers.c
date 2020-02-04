/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:12:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 11:23:43 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "events_parser.h"

int		check_floor_slope_input_box(void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;
	int			i;

	env = (t_env*)penv;
	sector = env->sectors[env->selected_floor];
	prec = sector.floor_slope;
	sector.floor_slope = ft_atof(env->input_box.str);
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
	{
		sector.floor_slope = prec;
		update_sector_slope(env, &sector);
		return (1);
	}
	if (env->player.sector == env->selected_floor)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
		{
			sector.floor_slope = prec;
			update_sector_slope(env, &sector);
			return (1);
		}
	}
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == env->selected_floor
			&& get_floor_at_pos(sector, env->enemies[i].pos, env) +
			env->enemies[i].scale + env->enemies[i].height_on_floor >=
			get_ceiling_at_pos(sector, env->enemies[i].pos, env))
		{
			sector.floor_slope = prec;
			update_sector_slope(env, &sector);
			return (1);
		}
		i++;
	}
	sector.floor_slope = env->sectors[env->selected_floor].floor_slope;
	update_sector_slope(env, &sector);
	return (0);
}

int		check_ceiling_slope_input_box(void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;
	int			i;

	env = (t_env*)penv;
	sector = env->sectors[env->selected_ceiling];
	prec = sector.ceiling_slope;
	sector.ceiling_slope = ft_atof(env->input_box.str);
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
	{
		sector.ceiling_slope = prec;
		update_sector_slope(env, &sector);
		return (1);
	}
	if (env->player.sector == env->selected_ceiling)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
		{
			sector.ceiling_slope = prec;
			update_sector_slope(env, &sector);
			return (1);
		}
	}
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == env->selected_ceiling
			&& env->enemies[i].pos.z + env->enemies[i].scale >=
			get_ceiling_at_pos(sector, env->enemies[i].pos, env))
		{
			sector.ceiling_slope = prec;
			update_sector_slope(env, &sector);
			return (1);
		}
		i++;
	}
	sector.ceiling_slope = env->sectors[env->selected_floor].ceiling_slope;
	update_sector_slope(env, &sector);
	return (0);
}

int		check_floor_height_input_box(void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;
	int			i;

	ft_printf("checking floor height\n");
	env = (t_env*)penv;
	sector = env->sectors[env->selected_floor];
	prec = sector.floor;
	sector.floor = ft_atof(env->input_box.str);
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
	{
		sector.floor = prec;
		update_sector_slope(env, &sector);
		return (1);
	}
	if (env->player.sector == env->selected_floor)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
		{
			sector.floor = prec;
			update_sector_slope(env, &sector);
			return (1);
		}
	}
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == env->selected_floor
			&& get_floor_at_pos(sector, env->enemies[i].pos, env) +
			env->enemies[i].scale + env->enemies[i].height_on_floor >=
			get_ceiling_at_pos(sector, env->enemies[i].pos, env))
		{
			sector.floor = prec;
			update_sector_slope(env, &sector);
			return (1);
		}
		i++;
	}
	sector.floor = env->sectors[env->selected_floor].floor;
	update_sector_slope(env, &sector);
	return (0);
}

int		check_ceiling_height_input_box(void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;
	int			i;

	env = (t_env*)penv;
	sector = env->sectors[env->selected_ceiling];
	prec = sector.ceiling;
	sector.ceiling = ft_atof(env->input_box.str);
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
	{
		sector.ceiling = prec;
		update_sector_slope(env, &sector);
		return (1);
	}
	if (env->player.sector == env->selected_ceiling)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
		{
			sector.ceiling = prec;
			update_sector_slope(env, &sector);
			return (1);
		}
	}
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == env->selected_ceiling
			&& env->enemies[i].pos.z + env->enemies[i].scale >=
			get_ceiling_at_pos(sector, env->enemies[i].pos, env))
		{
			sector.ceiling = prec;
			update_sector_slope(env, &sector);
			return (1);
		}
		i++;
	}
	sector.ceiling = prec;
	update_sector_slope(env, &sector);
	return (0);
}

int		check_texture_input_box(void *penv)
{
	int		texture;
	t_env	*env;

	env = (t_env*)penv;
	texture = ft_atoi(env->input_box.str);
	if (texture < -MAX_SKYBOX || texture >= MAX_WALL_TEXTURE)
		return (1);
	return (0);
}

int		check_sprite_input_box(void *penv)
{
	int		sprite;
	t_env	*env;

	env = (t_env*)penv;
	sprite = ft_atoi(env->input_box.str);
	if (sprite < 0 || sprite >= MAX_OBJECT_SPRITES)
		return (1);
	return (0);
}

int		check_scale_input_box(void *penv)
{
	double	scale;
	t_env	*env;

	env = (t_env*)penv;
	scale = ft_atof(env->input_box.str);
	if (scale < 0.1 || scale > 100)
		return (1);
	return (0);
}


int		check_damage_input_box(void *penv)
{
	int		damage;
	t_env	*env;

	env = (t_env*)penv;
	damage = ft_atof(env->input_box.str);
	if (damage < 0 || damage > 100)
		return (1);
	return (0);
}

int		check_light_data_input_box(void *penv)
{
	int		value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atoi(env->input_box.str);
	if (value <= -255 || value >= 255)
		return (1);
	return (0);
}

int		check_gravity_input_box(void *penv)
{
	double	value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atof(env->input_box.str);
	if (value > -0.1 || value < -10)
		return (1);
	return (0);
}

int		check_true_false_input_box(void *penv)
{
	int		value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atoi(env->input_box.str);
	if (value != 0 && value != 1)
		return (1);
	return (0);
}

int		check_portal_input_box(void *penv)
{
	int		value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atoi(env->input_box.str);
	if (value != 0 && value != 1)
		return (1);
	if (intersects_with_wall_no_portal_check(&env->
		sectors[env->editor.selected_sector], env->player.pos,
	env->editor.selected_wall, env))
		return (1);
	return (0);
}

int		check_health_input_box(void *penv)
{
	int		value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atoi(env->input_box.str);
	if (value <= 0 || value >= 10000)
		return (1);
	return (0);
}

int		check_speed_input_box(void *penv)
{
	double	value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atof(env->input_box.str);
	if (value < 0 || value > 100)
		return (1);
	return (0);
}
