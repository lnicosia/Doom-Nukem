/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:12:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/28 11:08:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "events_parser.h"

int		check_x_collision_event(t_event *event, void *penv)
{
	t_movement	movement;
	t_v3		move;
	t_env		*env;
	int			sector;

	env = (t_env*)penv;
	ft_bzero(&movement, sizeof(t_movement));
	movement.lowest_ceiling = find_lowest_ceiling(env, movement);
	movement = new_movement(env->player.sector, env->player.size_2d,
			env->player.eyesight, env->player.pos);
	move.x = event->incr;
	if (!event->speed)
	{
		move = env->player.pos;
		move.x = event->goal;
		if ((sector = get_sector_no_z(env, move)) == -1
			|| intersects_with_sector(&env->sectors[get_sector_no_z(env, move)],
			move, env))
			return (1);
	}
	else
	{
		move = check_collision(env, move, movement, 0);
		if (!move.x)
			return (1);
	}
	return (0);
}

int		check_y_collision_event(t_event *event, void *penv)
{
	t_movement	movement;
	t_v3		move;
	t_env		*env;
	int			sector;

	env = (t_env*)penv;
	ft_bzero(&movement, sizeof(t_movement));
	movement.lowest_ceiling = find_lowest_ceiling(env, movement);
	movement = new_movement(env->player.sector, env->player.size_2d,
			env->player.eyesight, env->player.pos);
	move.y = event->incr;
	if (!event->speed)
	{
		move = env->player.pos;
		move.y = event->goal;
		if ((sector = get_sector_no_z(env, move)) == -1
			|| intersects_with_sector(&env->sectors[get_sector_no_z(env, move)],
			move, env))
			return (1);
	}
	else
	{
		move = check_collision(env, move, movement, 0);
		if (!move.y)
			return (1);
	}
	return (0);
}

int		check_z_collision_event(t_event *event, void *penv)
{
	t_movement	movement;
	t_v3		move;
	t_env		*env;
	int			sector;

	env = (t_env*)penv;
	ft_bzero(&movement, sizeof(t_movement));
	movement.lowest_ceiling = find_lowest_ceiling(env, movement);
	movement = new_movement(env->player.sector, env->player.size_2d,
			env->player.eyesight, env->player.pos);
	move.z = event->incr;
	if (!event->speed)
	{
		move = env->player.pos;
		move.z = event->goal;
		if ((sector = get_sector_global(env, move)) == -1
			|| intersects_with_sector(&env->sectors[get_sector_no_z(env, move)],
			move, env))
			return (1);
	}
	else
	{
		move = check_collision(env, move, movement, 0);
		if ((event->incr > 0 && move.z > 0) || (event->incr < 0 && move.z < 0)
				|| (event->incr == 0 && move.z == 0))
			return (0);
	}
	return (1);
}

int		check_floor_slope_event(t_event *event, void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;
	Uint32		time;

	env = (t_env*)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	sector = env->sectors[event->check_param.sector];
	prec = sector.floor_slope;
	sector.floor_slope = event->start_value + time * event->incr;
	if (!event->speed)
		sector.floor_slope = event->goal;
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
	{
		sector.floor_slope = prec;
		update_sector_slope(env, &sector);
		return (1);
	}
	if (env->player.sector == event->check_param.sector)
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
	sector.floor_slope = prec;
	update_sector_slope(env, &sector);
	return (0);
}

int		check_ceiling_slope_event(t_event *event, void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;
	Uint32		time;

	env = (t_env*)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	sector = env->sectors[event->check_param.sector];
	prec = sector.ceiling_slope;
	sector.ceiling_slope = event->start_value + time * event->incr;
	if (!event->speed)
		sector.ceiling_slope = event->goal;
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
	{
		sector.ceiling_slope = prec;
		update_sector_slope(env, &sector);
		return (1);
	}
	if (env->player.sector == event->check_param.sector)
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
	sector.ceiling_slope = prec;
	update_sector_slope(env, &sector);
	return (0);
}

int		check_floor_event(t_event *event, void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;
	Uint32		time;

	env = (t_env*)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	sector = env->sectors[event->check_param.sector];
	prec = sector.floor;
	sector.floor = event->start_value + time * event->incr;
	if (!event->speed)
		sector.floor = event->goal;
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
	{
		sector.floor = prec;
		update_sector_slope(env, &sector);
		return (1);
	}
	if (env->player.sector == event->check_param.sector)
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
	sector.floor = prec;
	update_sector_slope(env, &sector);
	return (0);
}

int		check_ceiling_event(t_event *event, void *penv)
{
	t_env		*env;
	t_sector	sector;
	double		z;
	double		prec;
	Uint32		time;

	env = (t_env*)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	sector = env->sectors[event->check_param.sector];
	prec = sector.ceiling;
	sector.ceiling = event->start_value + time * event->incr;
	if (!event->speed)
		sector.ceiling = event->goal;
	update_sector_slope(env, &sector);
	if (sector.floor_max > sector.ceiling_min)
	{
		sector.ceiling = prec;
		update_sector_slope(env, &sector);
		return (1);
	}
	if (env->player.sector == event->check_param.sector)
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
	sector.ceiling = prec;
	update_sector_slope(env, &sector);
	return (0);
}

int		check_texture_event(t_event *event, void *penv)
{
	(void)penv;
	if ((event->incr > 0 && *(int*)event->target >= MAX_WALL_TEXTURE - 1)
			|| (event->incr < 0 && *(int*)event->target <= -MAX_SKYBOX)
			|| (!event->speed && ((int)event->goal >= MAX_WALL_TEXTURE
					|| (int)event->goal < -MAX_SKYBOX)))
		return (1);
	return (0);
}

int		check_sprite_event(t_event *event, void *penv)
{
	(void)penv;
	if ((event->incr > 0 && *(int*)event->target >= MAX_OBJECT_SPRITES - 1)
			|| (event->incr < 0 && *(int*)event->target <= 0)
			|| (!event->speed && ((int)event->goal >= MAX_OBJECT_SPRITES
					|| (int)event->goal < 0)))
		return (1);
	return (0);
}

int		check_scale_event(t_event *event, void *penv)
{
	t_env	*env;
	Uint32	time;

	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env = (t_env*)penv;
	if ((event->incr > 0 && event->start_value + time * event->incr > 100)
			|| (event->incr < 0 && event->start_value + time * event->incr < 0.1)
			|| (!event->speed && (event->goal > 100
					|| event->goal < 0.1)))
		return (1);
	return (0);
}

int		check_align_event(t_event *event, void *penv)
{
	t_env	*env;
	Uint32	time;

	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env = (t_env*)penv;
	if ((event->incr > 0 && event->start_value + time * event->incr > 1000000)
			|| (event->incr < 0
				&& event->start_value + time * event->incr < -1000000)
			|| (!event->speed && (event->goal > 1000000
					|| event->goal < -1000000)))
		return (1);
	return (0);
}

int		check_brightness_event(t_event *event, void *penv)
{
	t_env	*env;
	Uint32	time;

	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env = (t_env*)penv;
	if ((event->incr > 0 && event->start_value + time * event->incr >= 255)
			|| (event->incr < 0 && event->start_value + time * event->incr <= -255)
			|| (!event->speed && (event->goal >= 255
					|| event->goal <= -255)))
		return (1);
	return (0);
}

int		check_color_event(t_event *event, void *penv)
{
	t_env	*env;
	Uint32	time;

	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env = (t_env*)penv;
	if ((event->incr > 0 && event->start_value + time * event->incr >=
				0xFFFFFFFF)
			|| (event->incr < 0 && event->start_value + time * event->incr <= 0)
			|| (!event->speed && ((Uint32)event->goal > 0xFFFFFFFF
					|| (Uint32)event->goal <= 0)))
		return (1);
	return (0);
}

int		check_int_overflow_event(t_event *event, void *penv)
{
	t_env	*env;
	Uint32	time;

	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env = (t_env*)penv;
	if ((event->incr > 0
				&& event->start_value + time * event->incr >= 2147483646)
			|| (event->incr < 0
				&& event->start_value + time * event->incr <= -2147483648)
			|| (!event->speed && (event->goal >= 2147483646
					|| event->goal <= -2147483648)))
		return (1);
	return (0);
}

int		check_double_overflow_event(t_event *event, void *penv)
{
	t_env	*env;
	Uint32	time;

	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env = (t_env*)penv;
	if ((event->incr > 0
				&& event->start_value + time * event->incr >= 99999999999999)
			|| (event->incr < 0
				&& event->start_value + time * event->incr <= -99999999999999)
			|| (!event->speed && (event->goal >= 99999999999999
					|| event->goal <= -99999999999999)))
		return (1);
	return (0);
}

int		check_gravity_event(t_event *event, void *penv)
{
	t_env	*env;
	Uint32	time;

	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env = (t_env*)penv;
	if ((event->incr > 0 && event->start_value + time * event->incr > 10)
			|| (event->incr < 0 && event->start_value + time * event->incr < -10)
			|| (!event->speed && ((int)event->goal > 10
					|| (int)event->goal < -10)))
		return (1);
	return (0);
}

int		check_true_false_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if ((event->incr > 0 && *(int*)event->target == 1)
			|| (event->incr < 0 && *(int*)event->target == 0)
			|| (!event->speed && (int)event->goal != 1
				&& (int)event->goal != 0))
		return (1);
	return (0);
}

int		check_portal_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if ((event->incr > 0 && *(int*)event->target == 1)
			|| (event->incr < 0 && *(int*)event->target == 0)
			|| (!event->speed && (int)event->goal != 1
				&& (int)event->goal != 0))
		return (1);
	if (intersects_with_wall_no_portal_check(&env->sectors[event->
		check_param.sector], env->player.pos, event->check_param.wall, env))
		return (1);
	return (0);
}
