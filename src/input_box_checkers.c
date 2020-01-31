/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:12:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/31 14:23:48 by lnicosia         ###   ########.fr       */
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

	env = (t_env*)penv;
	sector = env->sectors[env->selected_floor];
	prec = sector.floor_slope;
	sector.floor_slope = ft_atof(env->input_box.str);
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
		return (1);
	if (env->player.sector == env->selected_floor)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
			return (1);
	}
	return (0);
}

int		check_ceiling_slope_input_box(void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;

	env = (t_env*)penv;
	sector = env->sectors[env->selected_ceiling];
	prec = sector.ceiling_slope;
	sector.ceiling_slope = ft_atof(env->input_box.str);
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
		return (1);
	if (env->player.sector == env->selected_ceiling)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
			return (1);
	}
	return (0);
}

int		check_floor_input_box(void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;

	env = (t_env*)penv;
	sector = env->sectors[env->selected_floor];
	prec = sector.floor;
	sector.floor = ft_atof(env->input_box.str);
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
		return (1);
	if (env->player.sector == env->selected_floor)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
			return (1);
	}
	return (0);
}

int		check_ceiling_input_box(void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;

	env = (t_env*)penv;
	sector = env->sectors[env->selected_ceiling];
	prec = sector.ceiling;
	sector.ceiling = ft_atof(env->input_box.str);
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
		return (1);
	if (env->player.sector == env->selected_ceiling)
	{
		z = get_floor_at_pos(sector, env->player.pos, env);
		if (z + env->player.eyesight + 1 >= get_ceiling_at_pos(sector,
					env->player.pos, env))
			return (1);
	}
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
	if (value <= -255 || value >= 255)
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
